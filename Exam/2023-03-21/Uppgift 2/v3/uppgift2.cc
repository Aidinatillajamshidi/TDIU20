#include <iostream>
#include <string>
#include <vector>

class Part
{
public:
  Part(std::string const& delmoment, int const& delhp, std::string const& delbetyg)
    : delmoment{delmoment}, delhp{delhp}, delbetyg{delbetyg}
  {
    
  }

  int get_delhp() const
  {
    return delhp;
  }

  std::string to_string() const
  {
    return " - " + delmoment + " (" + std::to_string(delhp) + "hp): " + delbetyg; 
  }
  
private:
  std::string delmoment;
  int delhp;
  std::string delbetyg;
};

class Course
{
public:
  Course(std::string const& kurskod, int const& kurshp)
    : kursmoment{}, kurskod{kurskod}, kurshp{kurshp}
  {
    
  }

  void add_examination(Part const& p)
  {
    kursmoment.push_back(p);
  }

  void print(std::ostream& os) const
  {
    if(completed())
      {
	os << "[X] " << kurskod << ":" << std::endl;
      }
    else
      {
	os << "[ ] " << kurskod << ":" << std::endl;
      }

    for(Part p : kursmoment)
      {
	os << p.to_string() << std::endl;
      }
  }

  bool completed() const
  {
    int tmp{0};

    for(Part p : kursmoment)
      {
	tmp += p.get_delhp();
      }
    
    return kurshp == tmp;
  }
  
private:
  std::vector<Part> kursmoment;
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
