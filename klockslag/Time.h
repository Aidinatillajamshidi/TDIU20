#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Time
{
//////////////////////////////////////////////////////////////////////////////
public:

  Time incorrect_time() const;
  Time time_check(Time &rhs) const;
  bool is_am() const;
  
  Time(int hour, int minute, int second);
  Time();
  Time(std::string str);
  std::string to_string(const bool = false) const;
  int get_hour() const;
  int get_minute() const;
  int get_second() const;

  bool operator<(Time const&) const;
  bool operator>(Time const&) const;
  bool operator>=(Time const&) const;
  bool operator<=(Time const&) const;
  bool operator==(Time const&) const;
  bool operator!=(Time const&) const;
  Time operator+(const int) const;
  Time operator-(const int) const;
  Time operator++(const int) const;
  Time& operator++();
  Time operator--(const int) const;
  Time& operator--();
//////////////////////////////////////////////////////////////////////////////
private:
  int hour;
  int minute;
  int second;

  void format_ostream(int const n, std::ostream &os) const;
  
};

std::ostream& operator<<(std::ostream &o, Time const&N);
std::istream& operator>>(std::istream &o, Time &N);


#endif
