#include <iostream>
#include <string>

#include "cloud.h"
#include "cloud.h"


void update(Cloud& cloud_1, Cloud& cloud_2)
{
  if ( cloud_1.overlaps(cloud_2) )
  {
    if ( cloud_1 > cloud_2 )
    {
      cloud_1.consume(cloud_2);
    }
    else
    {
      cloud_2.consume(cloud_1);
    }
  }
}

using namespace std;

int main()
{
  
  Cloud klas{"Klas", 1.0, 1.0, 5.0};
  Cloud eric{"Eric", 2.0, 3.0, 1.0};
  Cloud maria{"Maria", 3.0, 7.0, 8.0};
  Cloud nadim{"Nadim", 9.0, 15.0, 1.0};
  
  cout << klas << ", " << eric << endl;
  update(klas, eric);
  cout << klas << ", " << eric << endl;
  
  cout << klas << ", " << maria << endl;
  update(klas, maria);
  cout << klas << ", " << maria << endl;

  cout << maria << ", " << nadim << endl;
  update(maria, nadim);
  cout << maria << ", " << nadim << endl;
  
  return 0;
}
