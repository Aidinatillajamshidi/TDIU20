#ifndef CARGO_H
#define CARGO_H

#include <string>
#include <iostream>

class Cargo
{
 public:
  Cargo(std::string const& item, int const& value);

  friend std::ostream& operator<<(std::ostream& os, Cargo const& rhs);
  Cargo operator+(Cargo const& rhs);
  
 private:
  std::string item;
  int value;
};

#endif
