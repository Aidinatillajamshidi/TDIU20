#include "water_mixture.h"

Water_Mixture::Water_Mixture(double volume_water, double volume_b)
  : volume_water{volume_water}, volume_b{volume_b}
{
  
}

double Water_Mixture::volume() const
{
  return volume_water + volume_b;
}

double Water_Mixture::percentage_water() const
{
  return volume_water / volume() * 100;
}

double Water_Mixture::percentage_of_b() const
{
  return volume_b / volume() * 100; 
}

Water_Mixture Water_Mixture::operator+(Water_Mixture const& rhs) const
{
  return Water_Mixture{volume_water + rhs.volume_water, volume_b + rhs.volume_b};
}

Water_Mixture Water_Mixture::operator+(int rhs) const
{
  return Water_Mixture{volume_water + rhs, volume_b};
}
