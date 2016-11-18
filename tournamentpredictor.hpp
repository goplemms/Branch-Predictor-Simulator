#include "gshare.hpp"
#include "twobitmemory.hpp"

#include <iostream>


class TournamentPredictor{
  TwoBitMemory selector;
  GShare gshare;
  TwoBitMemory bimodal;
public:
  TournamentPredictor();
  bool checkMatch(unsigned int address, unsigned int result);
};
