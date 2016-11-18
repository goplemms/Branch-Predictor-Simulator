#ifndef GSHARE_H
#define GSHARE_H
#include "memory.hpp"
#include "twobitmemory.hpp"
#include <vector>
#include <iostream>

#define STR_TAK 3

using namespace std;

class GShare{
private:
  unsigned int lim;
  unsigned int gsbits;
  TwoBitMemory table;
  //vector<unsigned int> sotable;
  
  void storeCurrentResult(bool taken);
public:
  GShare(){this->lim = this->gsbits = 0; this->table = TwoBitMemory();};
  GShare(unsigned int lim);
  bool checkMatch(unsigned int address, unsigned int result);
  void increment();
  void decrement();
  //void increment(unsigned int index);
  //void decrement(unsigned int index);
};

#endif
