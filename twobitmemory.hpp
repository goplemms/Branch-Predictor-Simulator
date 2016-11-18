#ifndef TBM_H
#define TBM_H
#include "memory.hpp"

class TwoBitMemory : public Memory{
  public:
  void increment(unsigned int address);
  void decrement(unsigned int address);
  TwoBitMemory():Memory(){};
  TwoBitMemory(unsigned int table):Memory(4, table){};
  bool checkMatch(unsigned int address, unsigned int res);
  unsigned int getEntry(unsigned int address);
};


#endif
