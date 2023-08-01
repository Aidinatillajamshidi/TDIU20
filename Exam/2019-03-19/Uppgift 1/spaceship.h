#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <iostream>
#include <string>
#include <vector>

class Crew
{
 public:
  Crew(std::string const& name, std::string const& rank);

  std::string to_string() const;
  
 private:
  std::string name;
  std::string rank;
};

class Ship
{
 public:
  Ship(std::string const& name, int const& length);

  void add_crew_member(Crew const& c);
  void print(std::ostream& os) const;

 private:
  std::vector<Crew> members;
  std::string name;
  int length;
};


#endif
