#include "tree.h"

Branch::Branch(double length, double radius)
  : length{length}, radius{radius}
{
  
}

double Branch::volume() const
{
  return 3.14 * length * radius * radius;
}

Tree::Tree(std::string const& species)
  : branches{}, species{species}
{
  
}

void Tree::add_branch(Branch const& b)
{
  branches.push_back(b);
}

void Tree::print(std::ostream& os) const
{
  os << "Träder har " << branches.size() << " och är av arten " << species << "." << std::endl;
}

double Tree::volume() const
{
  double tmp{};

  for(Branch b : branches)
    {
      tmp += b.volume();
    }
  
  return tmp;
}
