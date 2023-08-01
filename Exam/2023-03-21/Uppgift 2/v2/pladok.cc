#include <iostream>
#include <string>
#include <vector>


class Part
{
public:
  Part(std::string const& delmoment, int const& delhp, std::string const& betyg)
    : delmoment{delmoment}, delhp{delhp}, betyg{betyg}
  {
      
  }

  int get_delhp() const
  {
    return delhp;
  }

  std::string to_string() const
  {
    return  " - " + delmoment + " (" + std::to_string(delhp) + "hp): " + betyg;
  }
  
private:
  std::string delmoment;
  int delhp;
  std::string betyg;
};


class Course
{
public:
  Course(std::string const& kurskod, int const& kurshp)
    : moment{}, kurskod{kurskod}, kurshp{kurshp}
  {
    
  }

  void add_examination(Part const& p)
  {
    moment.push_back(p);
  }

  void print(std::ostream& os)
  {
    if(completed())
      {
	os << "[X] " << kurskod << ":" << std::endl;
      }
    else
      {
	os << "[ ] " << kurskod << ":" << std::endl;
      }

    for(Part p : moment)
      {
	os << p.to_string() << std::endl;
      }
  }

  bool completed()
  {
    double tmp;
    
    for(Part p : moment)
      {
	tmp += p.get_delhp();
      }
    return tmp == kurshp;
  }
  
private:
  std::vector<Part> moment;
  std::string kurskod;
  int kurshp;
};

int main()
{
  
  Course tsiu05{"TSIU05", 8};
  
  tsiu05.add_examination( Part{"UPG1", 2, "G"} );
  tsiu05.add_examination( Part{"LAB1", 2, "G"} );
  tsiu05.add_examination( Part{"TEN1", 4, "5"} );
  
  Course tdiu20 {"TDIU20", 4};
  tdiu20.add_examination( Part{"LAB1", 3, "G"} );
    
  Course taiu10 {"TAIU10", 6};
  taiu10.add_examination( Part{"TEN1", 6, "4"} );
  
  tsiu05.print(std::cout);
  tdiu20.print(std::cout);
  taiu10.print(std::cout);
  
  return 0;
}
