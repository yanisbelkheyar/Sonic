#ifndef SONIC512_H_
#define SONIC512_H_

#include "crypto.h"

/*! \class Sonic512
 *  \brief Implementation of Sonic512
 */
class Sonic512 : public Crypto {
 public:
  static const uint32_t C[30];
  static void AddToOptions(cxxopts::Options& options);
  Sonic512(cxxopts::Options& options);
  
  class XOR2AND2;
  template <int R0, int R1, int R2> class Theta;
  template <int R0, int R1, int R2, int R3> class LinearRound;
  
  void permute(ConditionWordPtr *y, ConditionWordPtr *x, uint32_t val);
  
  bool Callback(std::string function, Characteristic& characteristic,
                std::mt19937& rng, Logfile& logfile);
   protected:
   int num_rounds_;
   uint64_t best_char_;
   ConditionWordPtr A[30][4];
   ConditionWordPtr X[31][4];
   ConditionWordPtr Y[31][4];
   ConditionWordPtr Xi[30][4];
   ConditionWordPtr Yi[30][4];
   ConditionWordPtr Z[30][4];
  
};

#endif  // SONIC512_H_
