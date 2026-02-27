// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
  if (value < 2)
    return false;
  if (value == 2 || value == 3)
    return true;
  if (value % 2 == 0)
    return false;
  for (uint64_t d = 3; d * d <= value; d += 2) {
    if (value % d == 0)
      return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t cnt = 0;
  uint64_t x = 1;
  while (cnt < n) {
    ++x;
    if (checkPrime(x))
      ++cnt;
  }
  return x;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t x = value + 1;
  while (true) {
    if (checkPrime(x))
      return x;
    ++x;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t s = 0;
  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i))
      s += i;
  }
  return s;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 3 || lbound >= hbound)
    return 0;
  uint64_t cnt = 0;
  uint64_t a = lbound;
  if (a < 2)
    a = 2;
  for (uint64_t i = a; i + 2 < hbound; ++i) {
    if (checkPrime(i) && checkPrime(i + 2))
      ++cnt;
  }
  return cnt;
}
