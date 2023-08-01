#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>

class Branch
{
public:
  Branch(double length, double radius);
  double volume() const;

private:
  double length{};
  double radius{};
};

class Tree
{
public:
  Tree(std::string const& species);

  void add_branch(Branch const& b);
  void print(std::ostream& os) const;
  double volume() const;

private:
  std::vector<Branch> branches{};
  std::string species{};
};

#endif
