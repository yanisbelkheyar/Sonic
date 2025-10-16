// \brief Automatically generated file. Do not edit!

#include "crypto_factory.h"

#include "sonic/sonic.h"
#include "sonic256hard/sonic256hard.h"
#include "sonic512/sonic512.h"
#include "tests/add2.h"
#include "tests/xor2.h"

Crypto* CryptoFactory(cxxopts::Options& options) {
  std::string function(options["function"].as<std::string>());
  if (function.compare("sonic") == 0) return new Sonic(options);
  if (function.compare("sonic256hard") == 0) return new Sonic256hard(options);
  if (function.compare("sonic512") == 0) return new Sonic512(options);
  if (function.compare("add2") == 0) return new Add2(options);
  if (function.compare("xor2") == 0) return new Xor2(options);
  std::cerr << "error: invalid crypto function" << std::endl;
  exit(-1);
}
