#ifndef SONIC_H_
#define SONIC_H_

#include "crypto.h"


/*! \class Sonic
 *  \brief Implementation of Sonic
 */
class Sonic : public Crypto {
 public:
  static const uint32_t C[30];
  static void AddToOptions(cxxopts::Options& options);
  Sonic(cxxopts::Options& options);
  
  class ID;
  class XOR2AND2;
  class isActive;
  
  template <int R0, int R1, int R2> class Theta;
  template <int R0, int R1, int R2, int R3> class LinearRound;
  
  void permute(ConditionWordPtr &yh, ConditionWordPtr &yl, ConditionWordPtr &xh, ConditionWordPtr &xl, uint32_t val);
  
  bool Callback(std::string function, Characteristic& characteristic,
                std::mt19937& rng, Logfile& logfile);
  
 protected:
   int num_rounds_;
   uint64_t best_char_;
   ConditionWordPtr Ah[30], Al[30];
   ConditionWordPtr Xh[31], Xl[31];
   ConditionWordPtr Yh[31], Yl[31];
   ConditionWordPtr Xhi[30], Xli[30];
   ConditionWordPtr Yhi[30], Yli[30];
   ConditionWordPtr Zh[30], Zl[30];
  
};

#endif  // SONIC_H_
