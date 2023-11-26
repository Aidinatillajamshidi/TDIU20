#include <iostream>
#include <string>
#include <stdexcept>
#include "Time.h"
#include <sstream>
#include "catch.hpp"
#include <fstream>

//Ändrat ordning på allting så bör stämma överens med .h fil.
//Finns några funktioner som ligger i private eller utanför som ej går att placera

//////////////////////////////////////////////////////////////////////////////
Time Time::incorrect_time() const
{
  if(hour > 23 || hour < 0)
    throw std::logic_error("Incorrect hour");
  if(minute > 59 || minute < 0)
    throw std::logic_error("Incorrect minute");
  if(second > 59 || second < 0)
    throw std::logic_error("Incorrect second");
  
  return Time();
}

Time Time::time_check(Time &rhs) const
{

  if(rhs.second > 59)
    {
      rhs.second -= 60;
      rhs.minute ++;
    }

  if(rhs.minute > 59)
    {
      rhs.minute -= 60;
      rhs.hour ++;
    }

  if(rhs.hour > 23)
    {
      rhs.hour -= 24;
    }

    if(rhs.second < 0)
    {
      rhs.second += 60;
      rhs.minute --;
    }

    if(rhs.minute < 0)
      {
	rhs.minute += 60;
	rhs.hour --;
      }
  
  if(rhs.hour < 0)
    {
      rhs.hour += 24;
    }

  return rhs;
}

bool Time::is_am() const
{
  if(hour < 12)
    {
      return true;
    }
  else
    {
      return false;
    }
}
//////////////////////////////////////////////////////////////////////////////
Time::Time(int h, int m, int s)
  : hour{h}, minute{m}, second{s}
{
  incorrect_time();
}

Time::Time()
  : hour{}, minute{}, second{}
{
}

Time::Time(std::string str)
  : hour{std::stoi(str.substr(0, 2))},
    minute{std::stoi(str.substr(3, 2))},
    second{std::stoi(str.substr(6, 2))}
{
  incorrect_time();
}

std::string Time::to_string(const bool am_pm_format) const
{
  std::ostringstream ss{};
  std::string str{};

  if(hour == 0)
    {
      format_ostream((hour), ss);
    }
  else if(am_pm_format && hour > 12)
    {
      format_ostream((hour - 12), ss);
    }
  else if(am_pm_format && hour < 1)
    {
      format_ostream((hour + 12), ss);
    }
  else
    {
      format_ostream(hour, ss);
    }

  ss << ':';
  format_ostream(minute, ss);
  ss << ':';
  format_ostream(second,ss);

  if(am_pm_format)
    {
      if(is_am())
	{
	  ss << " am";
	}
      else
	{
	  ss << " pm";
	}
    }
  return ss.str();
}

int Time::get_hour() const
{
  return hour;
}

int Time::get_minute() const
{
  return minute;
}

int Time::get_second() const
{
  return second;
}

void Time::format_ostream(int const n, std::ostream &os) const
{
  if(n < 10)
    {
      os << 0;
    }
  os << n;
}
//////////////////////////////////////////////////////////////////////////////
bool Time::operator<(Time const&rhs) const
{
  if(hour < rhs.hour)
    {
      return true;
    }
  else if(hour == rhs.hour && minute < rhs.minute)
    {
      return true;
    }
  else if(hour == rhs.hour && minute == rhs.minute && second < rhs.second)
    {
      return true;
    }
  return false;
}

bool Time::operator>(Time const&rhs) const
{
  return rhs < *this;
}

bool Time::operator>=(Time const&rhs) const
{
  return !(*this < rhs);
}

bool Time::operator<=(Time const&rhs) const
{
  return !(rhs < *this);
}

bool Time::operator==(Time const&rhs) const
{
  return !(rhs < *this || *this < rhs);
}

bool Time::operator!=(Time const&rhs) const
{
  return !(rhs <*this || *this < rhs);
}

Time Time::operator+(const int rhs) const
{
  Time t{hour, minute, second};
  t.second += rhs;
  time_check(t);
  
  return t;
}

Time Time::operator-(const int rhs) const
{
  Time t{hour, minute, second};
  t.second -= rhs;
  time_check(t);
  
  return t;
}

Time Time::operator++(int) const //i++
{
  Time t{hour, minute, second};
  t.second ++;
  time_check(t);
  
  return t;
}

Time& Time::operator++() //++i
{
  Time t{hour, minute, second};
  t.second ++;
  time_check(t);
  
  return *this;
}

Time Time::operator--(const int) const
{
  Time t{hour, minute, second};
  t.second --;
  time_check(t);
  
  return t;
}

Time& Time::operator--()
{
  Time t{hour, minute, second};
  t.second --;
  time_check(t);
  
  return *this;
}

std::ostream& operator<<(std::ostream& o, Time const& N)
{
  o << N.to_string();

  return o;
}

std::istream& operator>>(std::istream &o, Time &N)
{
  std::string T{};
  o >> T;

  try
    {
      N = Time{T};
    }
  catch(std::exception &e)
    {
      o.setstate(std::ios_base::failbit);
    }
  return o;
}
