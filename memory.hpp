#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class Memory{
protected:
  unsigned int lim;
  std::vector<unsigned int> table;
private:
  void increment(unsigned int address);
  void decrement(unsigned int address);
public:
  Memory(){this->lim = 0;};
  Memory(unsigned int lim, unsigned int table);
  bool checkMatch(unsigned int address, unsigned int actRes);
};

#endif
