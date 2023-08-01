#include "spaceship.h"

Crew::Crew(std::string const& name, std::string const& rank)
  : name{name}, rank{rank}
{
  
}

std::string Crew::to_string() const
{
  return name + " - " + rank;
}

Ship::Ship(std::string const& name, int const& length)
  : members{}, name{name}, length{length}
{
  
}

void Ship::add_crew_member(Crew const& c)
{
  members.push_back(c);
}

void Ship::print(std::ostream& os) const
{
  os << "name: " << name << "\n" << "length: " << length << "\n" << "crew:" << std::endl;

  for(Crew c : members)
    {
      os << c.to_string() << std::endl;
    }
}
