#include <iostream>

#include "tree.h"
#include "tree.h" // flawed for examination purposes

void print_tree_and_volume(Tree const yggdrasil) // flawed for examination purposes
{
    yggdrasil.print(std::cout);
    std::cout << "Volymen Ã¤r " << yggdrasil.volume() << " kubikmeter." << std::endl;
}

int main()
{
  Tree yggdrasil{"ask"};

  
    yggdrasil.add_branch(Branch{10, 4}); // length and radius
    yggdrasil.add_branch(Branch{2.7, 2.2});
    yggdrasil.add_branch(Branch{3.1, 2.5});
    yggdrasil.add_branch(Branch{0.5, 0.3});
    yggdrasil.add_branch(Branch{0.3, 0.1});
    yggdrasil.add_branch(Branch{0.8, 0.2});
  
    print_tree_and_volume(yggdrasil);
  
    return 0;
}
