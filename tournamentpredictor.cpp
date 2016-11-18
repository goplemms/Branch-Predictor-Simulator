#include "tournamentpredictor.hpp"
#include <iostream>

#define TABLE_SIZE 2048
#define GSBITS 11

using namespace std;

TournamentPredictor::TournamentPredictor(){
  this->selector = TwoBitMemory(TABLE_SIZE);
  this->gshare = GShare(GSBITS);
  this->bimodal = TwoBitMemory(TABLE_SIZE);
}

bool TournamentPredictor::checkMatch(unsigned int address, unsigned int result){
  bool bimodalResult = this->gshare.checkMatch(address, result);
  bool gshareResult = this->bimodal.checkMatch(address, result);
  bool useBimodal = ((this->selector.getEntry(address))/2 == 1);
  
  if(!gshareResult & bimodalResult){
    this->selector.increment(address);
  }else if(gshareResult & !bimodalResult){
    this->selector.decrement(address);
  }

  return (useBimodal)?bimodalResult:gshareResult;
}
