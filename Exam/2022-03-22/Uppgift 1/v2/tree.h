#ifndef TREE_H
#define TREE_H

#include <vector>
#include <iostream>
#include <string>

class Branch
{
 public:
  Branch(double length, double radius);
  double volume() const;

 private:
  double length;
  double radius;
};

class Tree
{
 public:
  Tree(std::string const& species);

  double volume() const;
  void add_branch(Branch const& b);
  void print(std::ostream& os) const;
  
  
 private:
  std::string species;
  std::vector<Branch> branches;
};



#endif
