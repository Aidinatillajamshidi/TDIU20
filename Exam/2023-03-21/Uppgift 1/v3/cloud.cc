#include "cloud.h"

Cloud::Cloud(std::string const& player, double const& x, double const& y, double const& r)
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

double Cloud::sq(double const& v) const
{
  return v * v;
}

std::string Cloud::to_string() const
{
  return player + "(" + std::to_string(r) + ")";
}

bool Cloud::operator>(Cloud const& rhs) const
{
  return r > rhs.r;
}

std::ostream& operator<<(std::ostream& os, Cloud const& rhs)
{
  return os << rhs.to_string();
}
