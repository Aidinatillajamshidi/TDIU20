#include "cargo.h"

Cargo::Cargo(std::string const& item, int const& value)
  : item{item}, value{value} 
{
  
}

std::ostream& operator<<(std::ostream& os, Cargo const& rhs)
{
  return os << rhs.item << " " << rhs.value;
}

Cargo Cargo::operator+(Cargo const& rhs)
{
  std::string n{item + rhs.item};
  int v{value + rhs.value};

  return Cargo{n, v};
}
