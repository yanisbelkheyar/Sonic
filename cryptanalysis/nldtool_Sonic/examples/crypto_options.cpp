// \brief Automatically generated file. Do not edit!

#include "crypto_options.h"

#include "sonic/sonic.h"
#include "sonic512/sonic512.h"
#include "tests/add2.h"
#include "tests/xor2.h"

void AddCryptoSpecificOptions(cxxopts::Options& options) {
  Sonic::AddToOptions(options);
  Sonic512::AddToOptions(options);
  Add2::AddToOptions(options);
  Xor2::AddToOptions(options);
}
