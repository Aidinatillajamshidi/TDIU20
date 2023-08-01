#ifndef CLOUD_H
#define CLOUD_H

#include <iostream>
#include <string>

class Cloud
{
 public:
  Cloud(std::string player, double x, double y, double r);

  bool overlaps(Cloud const& c) const;
  void consume(Cloud& c);

  bool operator>(Cloud const& rhs) const;

  std::string to_string() const;
  
 private:
  static double sq(double v);
  
  std::string player;
  double x;
  double y;
  double r;
};

std::ostream& operator<<(std::ostream& os, Cloud const& c);

#endif
