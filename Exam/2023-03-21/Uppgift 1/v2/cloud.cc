#include "cloud.h"

Cloud::Cloud(std::string player, double x, double y, double r)
  : player{player}, x{x}, y{y}, r{r}
{
  
}

bool Cloud::overlaps(Cloud const& c) const
{
  return (sq(x - c.x) + sq(y - c.y)) < sq(r + c.r);
}

void Cloud::consume(Cloud& c)
{
  r++;
  c.r = 0;
}

bool Cloud::operator>(Cloud const& rhs) const
{
  return r > rhs.r;
}

std::string Cloud::to_string() const
{
  return player + "(" + std::to_string(r) + ")";
}

std::ostream& operator<<(std::ostream& os, Cloud const& c)
{
  return os << c.to_string();
}

double Cloud::sq(double v)
{
  return v * v;
}
