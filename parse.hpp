#ifndef PARSE_HPP
#define PARSE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


namespace parse{
  std::vector<std::string> parseFile(char* filepath);
  std::vector<std::string> parseFile(char* filepath, char delim);
  std::vector<std::string> split(const std::string read, char delim);
}

#endif
