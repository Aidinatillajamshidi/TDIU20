#ifndef CLOUD_H
#define CLOUD_H

#include <iostream>
#include <string>

class Cloud
{
 public:
  Cloud(std::string const& player, double const& x, double const& y, double const& r);

  bool overlaps(Cloud const& c) const;
  void consume(Cloud& c);
  double sq(double const& v) const;
  
  std::string to_string() const;
  bool operator>(Cloud const& rhs) const;
  
 private:
  std::string player;
  double x;
  double y;
  double r;
};

std::ostream& operator<<(std::ostream& os, Cloud const& rhs);

#endif
