#include "twobitmemory.hpp"
#include <iostream>

using namespace std;

#define TABLE_SIZE (Memory::table.size())

void TwoBitMemory::increment(unsigned int address){
  unsigned int target = address % TABLE_SIZE;

  if(Memory::table.at(target) < this->lim){
    Memory::table.at(target)++;
  }
}
void TwoBitMemory::decrement(unsigned int address){
  unsigned int target = address % TABLE_SIZE;
  if(Memory::table.at(target) > 0){
    Memory::table.at(target)--;
  }
}

bool TwoBitMemory::checkMatch(unsigned int address, unsigned int res){
  unsigned int target = address % TABLE_SIZE;
  unsigned int hist = Memory::table.at(target);
  
  if(res == 1){
    this->increment(address);
  }else{
    this->decrement(address);
  }
  
  if(hist/2 == res){
    return true;
  }else{
    return false;
  }
}

unsigned int TwoBitMemory::getEntry(unsigned int address){
  unsigned int target = address % TABLE_SIZE;
  return Memory::table.at(target);
}

