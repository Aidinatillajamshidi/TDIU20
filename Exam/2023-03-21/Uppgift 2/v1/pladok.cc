#include <iostream>
#include <string>
#include <vector>

class Part
{
public:
  Part(std::string const& code, int const& hp, std::string const& grade)
    : code{code}, hp{hp}, grade{grade}
  {
    
  }

  std::string to_string() const
  {
    return code + " (" + std::to_string(hp) + "hp): " + grade;
  }

  int get_hp() const
  {
    return hp;
  }
  
private:
  std::string code;
  int hp;
  std::string grade;
};

class Course
{
public:
  Course(std::string const& code, int const& hp)
    : grades{}, code{code}, hp{hp}
  {
    
  }

  void add_examination(Part const& grade)
  {
    grades.push_back(grade);
  }

  bool completed() const
  {
    double result;

    for(Part grade : grades)
      {
	result += grade.get_hp();
      }

    return result == hp;
  }
  
  void print(std::ostream& os)
  {
    if(completed())
      {
	os << "[X] " << code << ":" << std::endl;
      }
    else
      {
	os << "[ ] " << code << ":" << std::endl;
      }

    for(Part p : grades)
      {
	os << " - " << p.to_string() << std::endl;
      }
  }
  
private:
  std::vector<Part> grades;
  std::string code;
  int hp;
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
