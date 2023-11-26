#include "ks.h" 
#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 


int main(int argc, char* argv[])
{

  const std::string error = ("Input needed:\n1. Number of iterations\n2. Number of lines\n3. Time interval\n4. Battery voltage");

  double time{};
  double volt{};
  int row{};
  int iteration{};
  
  if(argc != 5)
    {
      throw invalid_argument{"Wrong amount of arguments \n" + error};
    }
  try
    {
      iteration = stoi(argv[1]);
      row = stoi(argv[2]);
      time = stod(argv[3]);
      volt = stod(argv[4]);
    }
  catch(invalid_argument &e)
    {
      cerr << "Wrong amount of arguments" << endl;
      exit(0);
    }
  if (time <= 0 || volt <= 0 || iteration <= 0 || row <= 0)
    {
      cerr << "Input not within range" << endl;
    }
  
  cout << "========================================================================" << endl;
  vector<Component*> krets;
  
  Connection a{};
  Connection b{};
  Connection c{};
  Connection d{};

  krets.push_back(new Battery("Bat", volt, b, a));
  krets.push_back(new Resistor("R1", 6.0, a, c));
  krets.push_back(new Resistor("R2", 4.0, c, d)); 
  krets.push_back(new Resistor("R3", 8.0, d, b)); 
  krets.push_back(new Resistor("R4", 12.0, c, b));
  cout << "Krets 1: " << endl;
  simulate(krets, row, iteration, time);
  krets.clear();
  cout << "========================================================================" << endl;
  
  Connection a1{};
  Connection b1{};
  Connection c1{};
  Connection d1{};
  
  krets.push_back(new Battery("Bat", volt, a1, b1));
  krets.push_back(new Resistor("R1", 150.0, b1, c1));
  krets.push_back(new Resistor("R2", 50.0, b1, d1));
  krets.push_back(new Resistor("R3", 100.0, d1, c1));
  krets.push_back(new Resistor("R4", 300.0, c1, a1));
  krets.push_back(new Resistor("R5", 250.0, d1, a1));
  cout << "  Krets 2: " << endl;
  simulate(krets, row, iteration, time);
  krets.clear();
  cout << "========================================================================" << endl;
  
  Connection a2{};
  Connection b2{};
  Connection c2{};
  Connection d2{};
  
  krets.push_back(new Battery("Bat", volt, a2, b2));
  krets.push_back(new Resistor("R1", 150.0, b2, c2));
  krets.push_back(new Resistor("R2", 50.0, b2, d2));
  krets.push_back(new Capacitor("C3", 1.0, d2, c2));
  krets.push_back(new Resistor("R4", 300.0, c2, a2));
  krets.push_back(new Capacitor("C5", 0.5, d2, a2));
  cout << "  Krets 3: " << endl;
  simulate(krets, row, iteration, time);
  cout << "========================================================================" << endl;
  
  return 0;
}
	 
