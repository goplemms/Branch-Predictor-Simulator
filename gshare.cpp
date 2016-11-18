#include "gshare.hpp"

#define TRUNC_GSR this->gsbits %= (this->lim + 1)
#define TABLE_SIZE 2048

//New GShare
/*
GShare::GShare(unsigned int lim){
  this->lim = 0;
  for(int i = 0; i < lim; i++){
    this->lim <<= 1;
    this->lim += 1;
  }
  this->gsbits = 0;
  for(int i = 0; i < 2048; i++){
    this->sotable.push_back(STR_TAK);
  }
}

void GShare::increment(unsigned int index){
  if(this->sotable.at(index) < STR_TAK){
    this->sotable.at(index)++;
  }
}

void GShare::decrement(unsigned int index){
  if(this->sotable.at(index) > 0){
    this->sotable.at(index)--;
  }
}

bool GShare::checkMatch(unsigned int address, unsigned int result){
  unsigned int index = (address % this->lim) ^ (this->gsbits % this->lim);

  this->gsbits <<= 1;
  if(result == 1){
    this->gsbits += 1;
    if(this->sotable.at(index) < STR_TAK){
      this->sotable.at(index)++;
    }
  }else{
    if(this->sotable.at(index) > 0){
      this->sotable.at(index)--;
    }
  }
  this->gsbits &= this->lim;
  
  if((this->sotable.at(index))/2 == result){
    return true;
  }
  return false;
}
*/

GShare::GShare(unsigned int lim){
  this->lim = 0;
  for(int i = 0; i < lim; i++){
    this->lim <<= 1;
    this->lim += 1;
  }
  this->gsbits = 0;
  this->table = TwoBitMemory(TABLE_SIZE);
}




void GShare::storeCurrentResult(bool taken){
  this->gsbits <<= 1;
  if(taken){
    this->gsbits += 1;
  }
  TRUNC_GSR;
}

void GShare::increment(){
  this->gsbits <<= 1;
  this->gsbits += 1;
  TRUNC_GSR;
}

void GShare::decrement(){
  this->gsbits <<= 1;
  TRUNC_GSR;
}

bool GShare::checkMatch(unsigned int address, unsigned int result){
  unsigned int index = address;
  index %= TABLE_SIZE;
  index ^= this->gsbits;

  if(result == 1){
    this->increment();
  }else{
    this->decrement();
  }
  return this->table.checkMatch(index, result);
}

