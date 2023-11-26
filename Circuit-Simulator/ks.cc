#include "ks.h" 
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath> 

////////////////////////////////////////////////////////////////////////////////
//Component
Component::Component(std::string const& name, Connection & a, Connection & b):
name{name}, a{a}, b{b}
{}

double Component::get_volt() const
{
  double volt{};

  if (a.get_volt() >= b.get_volt())
    {
      volt = a.get_volt() - b.get_volt();
    }
  else
    {
      volt = b.get_volt() - a.get_volt();
    }
  return volt;
}
  
double Component::get_strom() const
{
  return 0.0; 
}

std::string Component::get_name() const
{
  return std::string();
}
////////////////////////////////////////////////////////////////////////////////
//Connection
double Connection::get_volt() const
{
  return volt;
}
////////////////////////////////////////////////////////////////////////////////
//Battery
Battery::Battery(std::string const name, double const volt, Connection & a, Connection & b)
  : Component(name, a, b), volt{volt}
{
}

double Battery::get_volt() const
{
  return volt;
}

double Battery::get_strom() const
{
  return 0.0;
}

void Battery::simulate(double)
{
  b.volt = 0;
  a.volt = volt;
}

////////////////////////////////////////////////////////////////////////////////
//Resistor
Resistor::Resistor(std::string const name, double const resistance, Connection &a, Connection &b)
  : Component(name, a, b), resistance{resistance}
{
}

double Resistor::get_strom() const //RÄTT
{
  return ((get_volt())/resistance);
}

void Resistor::simulate(double time)
{   
  double temp{b.volt};
  b.volt = (time * ((a.volt - b.volt)/resistance));
  a.volt = (a.volt - b.volt);
  b.volt += temp;
}
///////////////////////////////////////////////////////////////////////////////
//Capacitor
Capacitor::Capacitor(std::string const name, double const farad, Connection &a, Connection &b)
  : Component(name, a, b), farad{farad}, strom{0.0}
{
}

double Capacitor::get_strom() const
{
  return farad*(get_volt() - strom);
}

void Capacitor::simulate(double const time)
{
  double temp = get_strom() * time;
  
  strom = strom + temp;
  if(a.volt >= b.volt)
    {
      a.volt -= temp;
      b.volt += temp;
    }
  else
    {
      a.volt += temp;
      b.volt -= temp;
    }
}
////////////////////////////////////////////////////////////////////////////////
//Simulate
void simulate(std::vector<Component*> krets, int row, int iteration, double time)
{
  for(int i{0}; i < static_cast<int>(krets.size()); i++)
    {
      std::cout << std::right << std::setw(12) << std::setfill(' ') << krets.at(i) -> name;
    }
  std::cout << std::endl;

  for ( int i{0}; i < static_cast<int>(krets.size()); i++)
    {
      std::cout << std::setw(12) << "Volt Curr";
    } 
    std::cout << std::endl;

    for (int j{0}; j < row; j++)
    { 
      std::cout << "  ";
	for (int k{0}; k < iteration/row; k++)
	{
	  for( int l{0}; l < static_cast<int>(krets.size()); l++)
	    {
		krets.at(l)->simulate(time);
	    }
	}
	for (int r{0}; r < static_cast<int>(krets.size()); r++)
	{
	  std::cout << std::setw(5) << std::fixed << std::setprecision(2) << krets.at(r) -> get_volt() << " ";
	  std::cout << std::setw(4) << std::fixed << std::setprecision(2) << krets.at(r) -> get_strom() << "  ";
	}
	std::cout << std::endl;
    }
}


