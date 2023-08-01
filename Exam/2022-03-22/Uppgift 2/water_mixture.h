#ifndef WATER_MIXTURE_H
#define WATER_MIXTURE_H

#include <string>
#include <iostream>

class Water_Mixture
{
 public:
  Water_Mixture(double volume_water, double volume_b);

  double volume() const;
  double percentage_water() const;
  double percentage_of_b() const;

  Water_Mixture operator+(Water_Mixture const& rhs) const;
  Water_Mixture operator+(int rhs) const;
  
 private:
  double volume_water;
  double volume_b;
};

#endif
