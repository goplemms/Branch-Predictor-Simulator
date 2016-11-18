#ifndef OBM_H
#define OBM_H
#include "memory.hpp"

class OneBitMemory: public Memory{
  void increment(unsigned int address);
  void decrement(unsigned int address);
public:
  OneBitMemory():Memory(){};
  OneBitMemory(unsigned int table):Memory(2, table){};
  bool checkMatch(unsigned int address, unsigned int res);
  
  
};


#endif
