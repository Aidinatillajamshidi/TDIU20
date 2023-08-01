#include <iostream>
#include <string>

#include "cargo.h"

void print_cargo(Cargo const& c, std::ostream & os)
{
    os << c << std::endl;
}

int main()
{
  
    Cargo c1{"Beans", 5};
    const Cargo c2{"Latinum", 10000};
    const std::string tribbles{"Tribbles"};
    Cargo c3{tribbles, -5000};
    
    print_cargo(c1, std::cout);
    print_cargo(c2, std::cout);
    print_cargo(c3, std::cout);
    print_cargo(c1 + c2, std::cout);
    print_cargo(c1 + c2 + c3, std::cout);
  
}
