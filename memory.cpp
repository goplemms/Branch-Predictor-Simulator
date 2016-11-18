#include "memory.hpp"

#include <iostream>

using namespace std;

#define TABLE_SIZE this->table.size()

Memory::Memory(unsigned int lim, unsigned int table){
  this->lim = lim - 1;
  for(int i = 0; i < table; i++){
    this->table.push_back(this->lim);
  }
}
void Memory::increment(unsigned int address){
  unsigned int target = address % (TABLE_SIZE);
  if(this->table.at(target) < this->lim){
    this->table.at(target)++;
  }
}

void Memory::decrement(unsigned int address){
  unsigned int target = address % (TABLE_SIZE);
  if(this->table.at(target) > 0){
    this->table.at(target)--;
  }
}

bool Memory::checkMatch(unsigned int address, unsigned int actRes){
  cout << "Should not be called" << endl;
  return false;
}
