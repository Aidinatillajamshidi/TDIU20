#include <iostream>

#include "spaceship.h"

// Not used, but may not be modified. Should not give compilation errors with a correct
// implementation of Ship.
void print_ship_info(Ship const & s)
{
    s.print(std::cout);
}

int main()
{
    Ship ship{"Enterprise E", 685};
    ship.add_crew_member(Crew{"Riker", "First Officer"});
    ship.add_crew_member(Crew{"Picard", "Captain"});
    ship.add_crew_member(Crew{"Wessley", "Intern"});
    ship.print(std::cout);
}
