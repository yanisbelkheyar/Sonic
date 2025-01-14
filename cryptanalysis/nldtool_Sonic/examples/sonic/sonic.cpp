#include "sonic/sonic.h"

#include "bitslice_step.h"
#include "functions.h"
#include "linear_step.h"

const uint32_t Sonic::C[30] = {0x01, 0x20, 0x0c, 0x82, 0x70, 0x12, 0x46, 0xd9, 0x0d, 0xa2, 0x7c, 0x90, 0x36, 0xcb, 0x4b, 0x7b, 0x71, 0x32, 0x4a, 0x5b, 0x7d, 0xb0, 0x3a, 0x49, 0x3b, 0x69, 0x37, 0xeb, 0x47, 0xf9};


void Sonic::AddToOptions(cxxopts::Options& options) {}

void Sonic::permute(ConditionWordPtr &yh, ConditionWordPtr &yl, ConditionWordPtr &xh, ConditionWordPtr &xl, uint32_t val){
  
  yh = xh->Rotr(1);
  yl = xl->Rotr(1);
  
  int word_size = yh->GetWordSize();
  int word_size_x2 = word_size*2;
  
  
  for(int i = 0; i < word_size; i++){
    int source = (i * val) % word_size_x2;
    if(source < word_size)
      yl->SetConditionProxy(i, xl->GetConditionProxy(source%word_size));
    else
      yl->SetConditionProxy(i, xh->GetConditionProxy(source%word_size));
  }
  for(int i = word_size; i < word_size_x2; i++){
    int source = (i * val) % word_size_x2;
    if(source < word_size)
      yh->SetConditionProxy(i%word_size, xl->GetConditionProxy(source%word_size));
    else
      yh->SetConditionProxy(i%word_size, xh->GetConditionProxy(source%word_size));
  }

}



Sonic::Sonic(cxxopts::Options& options) : Crypto(options["word-size"].as<int>()),
      num_rounds_(options["num-rounds"].as<int>()),
      best_char_(std::numeric_limits<uint64_t>().max()) {
  for (int i = 0; i < num_rounds_+1; i++) {
   Xh[i] = AddConditionWord("Xh", i, 2*i, 0);
   Yh[i] = AddConditionWord("Yh", i, 2*i, 1);
   Xl[i] = AddConditionWord("Xl", i, 2*i+1, 0);
   Yl[i] = AddConditionWord("Yl", i, 2*i+1, 1);
   if(i != num_rounds_){
    //Ah[i] = AddConditionWord("Ah", i, 3*i, 2, SUBWORD);
    Al[i] = AddConditionWord("Al", i, 2*i, 3, SUBWORD);
    Zh[i] = AddConditionWord("Zh", i, 2*i, 2, SUBWORD);
    Zl[i] = AddConditionWord("Zl", i, 2*i+1, 2, SUBWORD);
   }
  }
  
  
  for (int i = 0; i < num_rounds_; i++) {
    permute(Xhi[i], Xli[i], Xh[i+1], Xl[i+1], 111);
    permute(Yhi[i], Yli[i], Yh[i+1], Yl[i+1], 111);
    
    
    ConditionWordPtr c(new ConditionWord(C[30-num_rounds_+i],word_size_));
    Add(new BitsliceStep<XOR<5>>(word_size_, Xh[i], Xh[i]->Shr(7), Xl[i]->Shl(word_size_-7), Xh[i]->Shr(32), Xl[i]->Shl(word_size_-32),  Yhi[i]));
    Add(new BitsliceStep<XOR<5>>(word_size_, Xl[i], Xl[i]->Shr(7), Xh[i]->Shl(word_size_-7), Xl[i]->Shr(32), Xh[i]->Shl(word_size_-32), Al[i]));
    Add(new BitsliceStep<XOR<2>>(word_size_, Al[i], c, Yli[i]));
    Add(new LinearStep<Sonic::Theta<0, 7, 32>>(word_size_, Xh[i], Xl[i], Yhi[i], Al[i]));
    Add(new BitsliceStep<XOR2AND2>(word_size_, Xh[i]->Shr(1), Xl[i]->Shl(word_size_-1), Xh[i], Zh[i]));
    Add(new BitsliceStep<XOR2AND2>(word_size_, Xl[i]->Shr(1), Xh[i]->Shl(word_size_-1), Xl[i], Zl[i]));
    //Add(new BitsliceStep<isActive>(word_size_, Xh[i]->Shr(1), Xl[i]->Shl(word_size_-1), Xh[i], Ah[i]));
    //Add(new BitsliceStep<isActive>(word_size_, Xl[i]->Shr(1), Xh[i]->Shl(word_size_-1), Xl[i], Al[i]));
    Add(new BitsliceStep<XOR<4>>(word_size_, Zh[i], Xh[i]->Shr(5), Xl[i]->Shl(word_size_-5), Yh[i], Xhi[i]));
    Add(new BitsliceStep<XOR<4>>(word_size_, Zl[i], Xl[i]->Shr(5), Xh[i]->Shl(word_size_-5), Yl[i], Xli[i]));

  }
}


class Sonic::ID : public F {
 public:
  static constexpr char kName[] = "ID";
  static const int kNumInputs = 1;
  static const int kNumOutputs = 1;
  template <class T>
  static void f(const T x[kNumInputs], T y[kNumOutputs]) {
    y[0] = x[0];
  }
};

constexpr char Sonic::ID::kName[];


class Sonic::XOR2AND2 : public F {
 public:
  static constexpr char kName[] = "XOR2AND2";
  static const int kNumInputs = 3;
  static const int kNumOutputs = 1;
  template <class T>
  static void f(const T x[kNumInputs], T y[kNumOutputs]) {
    y[0] = (x[0]^x[1])&x[2];
  }
};

constexpr char Sonic::XOR2AND2::kName[];

class Sonic::isActive : public F {
 public:
  static constexpr char kName[] = "ISA";
  static const int kNumInputs = 3;
  static const int kNumOutputs = 1;
  static void f(const Pair x[kNumInputs], Pair y[kNumOutputs]) {
    y[0].first = y[0].second =
        (x[0].first ^ x[0].second ^ x[1].first ^ x[1].second) |
        (x[2].first ^ x[2].second);
  }
};

constexpr char Sonic::isActive::kName[];


template <int R0, int R1, int R2>
class Sonic::Theta : public F {
 public:
  static constexpr char kName[] = "Theta";
  static const int kNumInputs = 2;
  static const int kNumOutputs = 2;
  template <class T>
  static void f(int word_size, const T x[kNumInputs], T y[kNumOutputs]) {
    y[0] = nldtool::Shr(x[0], R0, word_size) ^ nldtool::Shl(x[1], word_size - R0, word_size) ^
           nldtool::Shr(x[0], R1, word_size) ^ nldtool::Shl(x[1], word_size - R1, word_size) ^
           nldtool::Shr(x[0], R2, word_size) ^ nldtool::Shl(x[1], word_size - R2, word_size);
    y[1] = nldtool::Shr(x[1], R0, word_size) ^ nldtool::Shl(x[0], word_size - R0, word_size) ^
           nldtool::Shr(x[1], R1, word_size) ^ nldtool::Shl(x[0], word_size - R1, word_size) ^
           nldtool::Shr(x[1], R2, word_size) ^ nldtool::Shl(x[0], word_size - R2, word_size);
  }
};

template <int R0, int R1, int R2>
constexpr char Sonic::Theta<R0, R1, R2>::kName[];


template <int R0, int R1, int R2, int R3>
class Sonic::LinearRound : public F {
 public:
  static constexpr char kName[] = "LinearRound";
  static const int kNumInputs = 2;
  static const int kNumOutputs = 2;
  template <class T>
  static void f(int word_size, const T x[kNumInputs], T y[kNumOutputs]) {
    y[0] = nldtool::Shr(x[0], R0, word_size) ^ nldtool::Shl(x[1], word_size - R0, word_size) ^
           nldtool::Shr(x[0], R1, word_size) ^ nldtool::Shl(x[1], word_size - R1, word_size) ^
           nldtool::Shr(x[0], R2, word_size) ^ nldtool::Shl(x[1], word_size - R2, word_size);
    y[1] = nldtool::Shr(x[1], R0, word_size) ^ nldtool::Shl(x[0], word_size - R0, word_size) ^
           nldtool::Shr(x[1], R1, word_size) ^ nldtool::Shl(x[0], word_size - R1, word_size) ^
           nldtool::Shr(x[1], R2, word_size) ^ nldtool::Shl(x[0], word_size - R2, word_size);
  }
};

template <int R0, int R1, int R2, int R3>
constexpr char Sonic::LinearRound<R0, R1, R2, R3>::kName[];


bool Sonic::Callback(std::string function, Characteristic& characteristic,
                     std::mt19937& rng, Logfile& logfile) {
  if (function.empty())
    return true;
  else if (function.compare("found") == 0) {
    
    
    
    uint64_t cost = 0;
    uint64_t trunc_diff_h[30];
    uint64_t trunc_diff_l[30];
    uint64_t trunc_cost[30];
    for (int r = 0; r < num_rounds_; r++) {
      uint64_t xh = 0;
      uint64_t xl = 0;
      
      xh |= characteristic.GetConditionWordMask(
          [](BitCondition bc) { return bc == BitCondition("x"); },
          characteristic.GetCrypto()->GetConditionWordIndex("Xh", r));
      xh |= characteristic.GetConditionWordMask(
          [](BitCondition bc) { return bc == BitCondition("u"); },
          characteristic.GetCrypto()->GetConditionWordIndex("Xh", r));
      xh |= characteristic.GetConditionWordMask(
          [](BitCondition bc) { return bc == BitCondition("n"); },
          characteristic.GetCrypto()->GetConditionWordIndex("Xh", r));
          
      xl |= characteristic.GetConditionWordMask(
          [](BitCondition bc) { return bc == BitCondition("x"); },
          characteristic.GetCrypto()->GetConditionWordIndex("Xl", r));
      xl |= characteristic.GetConditionWordMask(
          [](BitCondition bc) { return bc == BitCondition("u"); },
          characteristic.GetCrypto()->GetConditionWordIndex("Xl", r));
      xl |= characteristic.GetConditionWordMask(
          [](BitCondition bc) { return bc == BitCondition("n"); },
          characteristic.GetCrypto()->GetConditionWordIndex("Xl", r));
      
      
      trunc_diff_h[r] = xh |((xh>>1)^(xl<<63));
      trunc_diff_l[r] = xl |((xl>>1)^(xh<<63));
      trunc_cost[r] = nldtool::HammingWeight(trunc_diff_h[r]);
      trunc_cost[r] += nldtool::HammingWeight(trunc_diff_l[r]);
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