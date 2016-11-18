#include "onebitmemory.hpp"


#include <iostream>

using namespace std;

#define TABLE_SIZE Memory::table.size();

void OneBitMemory::increment(unsigned int address){
  unsigned int target = address % TABLE_SIZE;
  if(Memory::table.at(target) == 0){
    Memory::table.at(target)++;
  }
}
void OneBitMemory::decrement(unsigned int address){
  unsigned int target = address % TABLE_SIZE;
  if(Memory::table.at(target) == 1){
    Memory::table.at(target)--;
  }
}

bool OneBitMemory::checkMatch(unsigned int address, unsigned int res){
  unsigned int target = address % TABLE_SIZE;
  unsigned int hist = Memory::table.at(target);

  
  //Cout Dump
  /*
  cout << "Paramter Address: " << address << endl;
  cout << "Result: " << res << endl;
  cout << "Target: " << target << endl;
  cout << "Hist @ Target: " << hist << endl;
  */
  if(res == 1){
    //    cout << "Incremented" << endl;
    this->increment(address);
  }else{
    //    cout << "Decremented" << endl;
    this->decrement(address);
  }

  //  cout << "New Hist: " << Memory::table.at(target) << endl;
  
  // cin.ignore();
  
  if(hist == res){
    return true;
  }
  return false;
}

