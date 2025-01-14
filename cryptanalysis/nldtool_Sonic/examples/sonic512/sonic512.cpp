#include "sonic512/sonic512.h"

#include "bitslice_step.h"
#include "functions.h"
#include "linear_step.h"
#include <string>

const uint32_t Sonic512::C[30] = {0x01, 0x20, 0x0c, 0x82, 0x70, 0x12, 0x46, 0xd9, 0x0d, 0xa2, 0x7c, 0x90, 0x36, 0xcb, 0x4b, 0x7b, 0x71, 0x32, 0x4a, 0x5b, 0x7d, 0xb0, 0x3a, 0x49, 0x3b, 0x69, 0x37, 0xeb, 0x47, 0xf9};



void Sonic512::permute(ConditionWordPtr *y, ConditionWordPtr *x, uint32_t val){
  
  for(int i = 0; i < 4; i++)
    y[i] = x[i]->Rotr(1);
  
  int word_size = y[0]->GetWordSize();
  int word_size_x4 = word_size*4;
  
  for(int k = 0; k < 4; k++)
    for(int i = 0; i < word_size; i++){
      int source = ((i + 64*k) * val) % word_size_x4;
      y[k]->SetConditionProxy(i, x[source/word_size]->GetConditionProxy(source%word_size));
    }


}



void Sonic512::AddToOptions(cxxopts::Options& options) {}

Sonic512::Sonic512(cxxopts::Options& options) : Crypto(options["word-size"].as<int>()),
      num_rounds_(options["num-rounds"].as<int>()),
      best_char_(std::numeric_limits<uint64_t>().max()) {
  
  for(int k = 3; k >= 0; k--)
    for (int i = 0; i < num_rounds_+1; i++) {
      X[i][k] = AddConditionWord("X"+std::to_string(k), i, 4*i+k, 0);
      Y[i][k] = AddConditionWord("Y"+std::to_string(k), i, 4*i+k, 1);

      if(i != num_rounds_){
        A[i][k] = AddConditionWord("A"+std::to_string(k), i, 4*i+k, 3, SUBWORD);
        Z[i][k] = AddConditionWord("Z"+std::to_string(k), i, 4*i+k, 2, SUBWORD);
      }
    }
    
  for (int i = 0; i < num_rounds_; i++) {
    permute(Xi[i], X[i+1], 111);
    permute(Yi[i], Y[i+1], 111);
    
    
    ConditionWordPtr c(new ConditionWord(C[30-num_rounds_+i],word_size_));
    for(int k = 1; k < 4; k++)
      Add(new BitsliceStep<XOR<5>>(word_size_, X[i][k], X[i][k]->Shr(7), X[i][(k-1+4)%4]->Shl(word_size_-7), X[i][k]->Shr(32), X[i][(k-1+4)%4]->Shl(word_size_-32),  Yi[i][k]));
    
    Add(new BitsliceStep<XOR<5>>(word_size_, X[i][0], X[i][0]->Shr(7), X[i][(0-1+4)%4]->Shl(word_size_-7), X[i][0]->Shr(32), X[i][(0-1+4)%4]->Shl(word_size_-32),  A[i][0]));

    Add(new BitsliceStep<XOR<2>>(word_size_, A[i][0], c, Yi[i][0]));
    //Add(new LinearStep<Sonic512::Theta<0, 7, 32>>(word_size_, X[i][0], X[i][1], X[i][2], X[i][3], A[i][0], Yi[i][1], Yi[i][2], Yi[i][3]));
    Add(new LinearStep<Sonic512::LinearRound<0, 7, 32, 5>>(word_size_, X[i][0], X[i][1], X[i][2], X[i][3], Y[i][0], Y[i][1], Y[i][2], Y[i][3], Z[i][0], Z[i][1], Z[i][2], Z[i][3], A[i][0], Yi[i][1], Yi[i][2], Yi[i][3], Xi[i][0], Xi[i][1], Xi[i][2], Xi[i][3]));
    for(int k = 0; k < 4; k++){
      Add(new BitsliceStep<XOR2AND2>(word_size_, X[i][k]->Shr(1), X[i][(k-1+4)%4]->Shl(word_size_-1), X[i][k], Z[i][k]));
      Add(new BitsliceStep<XOR<4>>(word_size_, Z[i][k], X[i][k]->Shr(5), X[i][(k-1+4)%4]->Shl(word_size_-5), Y[i][k], Xi[i][k]));
    }

  }
}


class Sonic512::XOR2AND2 : public F {
 public:
  static constexpr char kName[] = "XOR2AND2";
  static const int kNumInputs = 3;
  static const int kNumOutputs = 1;
  template <class T>
  static void f(const T x[kNumInputs], T y[kNumOutputs]) {
    y[0] = (x[0]^x[1])&x[2];
  }
};

constexpr char Sonic512::XOR2AND2::kName[];


template <int R0, int R1, int R2>
class Sonic512::Theta : public F {
 public:
  static constexpr char kName[] = "Theta";
  static const int kNumInputs = 4;
  static const int kNumOutputs = 4;
  template <class T>
  static void f(int word_size, const T x[kNumInputs], T y[kNumOutputs]) {
    
    for(int k = 0; k < 4; k++)
      y[k] = nldtool::Shr(x[k], R0, word_size) ^ nldtool::Shl(x[(k-1+4)%4], word_size - R0, word_size) ^
             nldtool::Shr(x[k], R1, word_size) ^ nldtool::Shl(x[(k-1+4)%4], word_size - R1, word_size) ^
             nldtool::Shr(x[k], R2, word_size) ^ nldtool::Shl(x[(k-1+4)%4], word_size - R2, word_size);

  }
};

template <int R0, int R1, int R2>
constexpr char Sonic512::Theta<R0, R1, R2>::kName[];



template <int R0, int R1, int R2, int R3>
class Sonic512::LinearRound : public F {
 public:
  static constexpr char kName[] = "LinearRound";
  static const int kNumInputs = 12;
  static const int kNumOutputs = 8;
  template <class T>
  static void f(int word_size, const T x[kNumInputs], T y[kNumOutputs]) {
    
    for(int k = 0; k < 4; k++){
      y[k] = nldtool::Shr(x[k], R0, word_size) ^ nldtool::Shl(x[(k-1+4)%4], word_size - R0, word_size) ^
             nldtool::Shr(x[k], R1, word_size) ^ nldtool::Shl(x[(k-1+4)%4], word_size - R1, word_size) ^
             nldtool::Shr(x[k], R2, word_size) ^ nldtool::Shl(x[(k-1+4)%4], word_size - R2, word_size);
      y[k+4] = nldtool::Shr(x[k], R3, word_size) ^ nldtool::Shl(x[(k-1+4)%4], word_size - R3, word_size) ^
             x[k+4] ^ x[k+8];
    }

  }
};

template <int R0, int R1, int R2, int R3>
constexpr char Sonic512::LinearRound<R0, R1, R2, R3>::kName[];




bool Sonic512::Callback(std::string function, Characteristic& characteristic,
                     std::mt19937& rng, Logfile& logfile) {
  if (function.empty())
    return true;
  else if (function.compare("found") == 0) {
    
    
    
    uint64_t cost = 0;
    uint64_t trunc_diff[30][4];
    uint64_t trunc_cost[30] = {0};
    for (int r = 0; r < num_rounds_; r++) {
      uint64_t x[4] = {0};
      
      for(int k = 0; k < 4; k++){
        x[k] |= characteristic.GetConditionWordMask(
            [](BitCondition bc) { return bc == BitCondition("x"); },
            characteristic.GetCrypto()->GetConditionWordIndex("X"+std::to_string(k), r));
        x[k] |= characteristic.GetConditionWordMask(
            [](BitCondition bc) { return bc == BitCondition("u"); },
            characteristic.GetCrypto()->GetConditionWordIndex("X"+std::to_string(k), r));
        x[k] |= characteristic.GetConditionWordMask(
            [](BitCondition bc) { return bc == BitCondition("n"); },
            characteristic.GetCrypto()->GetConditionWordIndex("X"+std::to_string(k), r));
      }
          
      
      for(int k = 0; k < 4; k++)
        trunc_diff[r][k] = x[k] |((x[k]>>1)^(x[(k-1+4)%4]<<63));
      

      for(int k = 0; k < 4; k++)
        trunc_cost[r] += nldtool::HammingWeight(trunc_diff[r][k]);
      cost += trunc_cost[r];
    }
    if (cost < best_char_) {
      logfile << "found new characteristic" << std::endl;
      logfile << "cost: " << cost << std::endl;
      characteristic.WriteCharacteristic(logfile);
      best_char_ = cost;
    }
    return true;
  }
  assert(false);
  return false;
}
