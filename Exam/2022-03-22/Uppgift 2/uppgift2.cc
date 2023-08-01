#include <iostream>

#include "water_mixture.h"
#include "water_mixture.h" // flawed for examination purposes

using namespace std;

void print(string const s, Water_Mixture const m) // flawed for examination purposes
{
  cout << "LÃ¶sningen " << s
       << " Ã¤r totalt " << m.volume()
       << " cl med " << m.percentage_water()
       << "% vatten och " << m.percentage_of_b()
       << "% etanol." << endl;
}

int main()
{
  
  Water_Mixture const loka {33, 0};
  Water_Mixture const absolut {10, 190};
  Water_Mixture handsprit {loka + absolut + 20};
  
   print("loka", loka);
   print("absolut", absolut);
   print("handsprit", handsprit);
  
  return 0;
}
