#include "catch.hpp"
#include "Time.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;

//Gått genom allt nu och förhoppningsvis finns alla test_cases som ska vara med.
//La även till --i, i--, ++i och i++.
//La till mer test_cases vid dygnomslag. Tror det finns på alla nu där det ska testat.


  TEST_CASE ("Constructors and getters")
{
   SECTION("Default")
   {
      Time empty{};
      CHECK( empty.get_hour()   == 0 );
      CHECK( empty.get_minute() == 0 );
      CHECK( empty.get_second() == 0 );
   }

   SECTION("Integer")
   {
      Time t0{0,0,0};
      Time t1{12,30,30};
      Time t2{23,59,59};

      CHECK_THROWS( Time{13,35,60} );
      CHECK_THROWS( Time{13,60,35} );
      CHECK_THROWS( Time{24,35,35} );

      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );
   }


   SECTION("String")
     {
       Time t0{"00:00:00"};
       Time t1{"12:30:30"};
       Time t2{"23:59:59"};

       CHECK_THROWS( Time{"13:35:60"} );
       CHECK_THROWS( Time{"13:60:35"} );
       CHECK_THROWS( Time{"24:35:35"} );

       CHECK( t0.get_hour()   == 0 );
       CHECK( t0.get_minute() == 0 );
       CHECK( t0.get_second() == 0 );
       CHECK( t1.get_hour()   == 12 );
       CHECK( t1.get_minute() == 30 );
       CHECK( t1.get_second() == 30 );
       CHECK( t2.get_hour()   == 23 );
       CHECK( t2.get_minute() == 59 );
       CHECK( t2.get_second() == 59 );
     }
}


TEST_CASE ("is_am") 
{
   Time t0{"05:00:00"};
   Time t1{"14:00:00"};
   Time t2{"10:00:00"};
   Time t3{"23:50:00"};
   Time t4{"23:59:59"};
   Time t5{"11:59:59"};
   Time t6{"12:00:00"};
   Time t7{"00:00:00"};

   CHECK       ( t0.is_am() );
   CHECK_FALSE ( t1.is_am() );
   CHECK       ( t2.is_am() );
   CHECK_FALSE ( t3.is_am() );
   CHECK_FALSE ( t4.is_am() );
   CHECK       ( t5.is_am() );
   CHECK_FALSE ( t6.is_am() );
   CHECK       ( t7.is_am() );
}

TEST_CASE ("to_string")
{
   Time t0{};
   Time t1{11, 59, 59};
   Time t2{12, 0, 0};
   Time t3{13, 0, 0};
   Time t4{23, 59, 59};
   Time t5{0, 0, 0};

   SECTION("24 hour format no argument")
   {
      CHECK( t0.to_string() == "00:00:00");
      CHECK( t1.to_string() == "11:59:59");
      CHECK( t2.to_string() == "12:00:00");
      CHECK( t3.to_string() == "13:00:00");
      CHECK( t4.to_string() == "23:59:59");
   }

   SECTION("24 hour format with argument")
   {
     CHECK( t0.to_string(false) == "00:00:00");
     CHECK( t1.to_string(false) == "11:59:59");
     CHECK( t2.to_string(false) == "12:00:00");
     CHECK( t3.to_string(false) == "13:00:00");
     CHECK( t4.to_string(false) == "23:59:59");
     CHECK( t5.to_string(false) == "00:00:00");
   }

   SECTION("12 hour format")
   {
     CHECK( t0.to_string(true) == "00:00:00 am");
     CHECK( t1.to_string(true) == "11:59:59 am");
     CHECK( t2.to_string(true) == "12:00:00 pm");
     CHECK( t3.to_string(true) == "01:00:00 pm");
     CHECK( t4.to_string(true) == "11:59:59 pm");
     CHECK( t5.to_string(true) == "00:00:00 am");
   }
}
//////////////////////////////////////////////////////////////////////////////
TEST_CASE ("< & >")
{
  Time t0{11, 59, 59};
  Time t1{13, 59, 59};
  Time t2{00, 00, 00};
  Time t3{23, 59, 59};
  Time t4{10, 59, 59};
  Time t5{14, 59, 59};

  CHECK(t0 < t1);
  CHECK(t0 < t5);
  CHECK_FALSE(t0 < t4);
  CHECK(t0 > t4);
  CHECK_FALSE(t2 > t3);
  CHECK(t2 < t3);
}

TEST_CASE (" >= & <= ")
{
  Time t0{11, 59, 59};

  CHECK(t0 >= t0);
  CHECK(t0 >= Time{10, 59, 59});
  CHECK(t0 <= t0);
  CHECK(t0 <= Time{12, 00, 00});
}

TEST_CASE ("== & !=")
{
  Time t0{11, 59, 59};

  CHECK(t0 == t0);
  CHECK_FALSE(t0 == Time{12, 00, 00 });
  CHECK_FALSE(t0 != Time{12, 59, 59});
}

TEST_CASE("+1/ -1")
{
  Time t0{00, 00, 00};
  Time t1{00, 00, 01};
  Time t2{00, 01, 00};
  Time t3{00, 00, 59};
  Time t4{00, 00, 00};

  t0 = t0 + 1;
  t1 = t1 - 1;
  t2 = t2 - 1;
  t3 = t3 + 1;
  t4 = t4 - 1;
  
  CHECK((t0.to_string()) == "00:00:01");
  CHECK((t1.to_string()) == "00:00:00");
  CHECK((t2.to_string()) == "00:00:59");
  CHECK((t3.to_string()) == "00:01:00");
  CHECK((t4.to_string()) == "23:59:59");
}

TEST_CASE("+ & -") //Addera och subtrahera med N heltal (SEKUNDER)
{
  Time t1{10, 00, 00};
  Time t2{23, 59, 00};
  Time t3{23, 59, 00};
  Time t4{00, 00, 00};
  Time t5{00, 00, 00};

  t1 = t1 + 10;
  t2 = t2 - 60;
  t3 = t3 + 60;
  t4 = t4 + 65;
  t5 = t5 - 1;

  CHECK((t1.to_string()) == "10:00:10");
  CHECK((t2.to_string()) == "23:58:00");
  CHECK((t3.to_string()) == "00:00:00");
  CHECK((t4.to_string()) == "00:01:05");
  CHECK((t5.to_string()) == "23:59:59");
}

TEST_CASE("i++")
{
  Time t1{21, 59, 59};
  Time t2{23, 59, 59};

  CHECK_FALSE((t1++).to_string() == "21:59:59");
  CHECK((t1++).to_string() == "22:00:00");
  CHECK_FALSE((t2++).to_string() == "23:59:59");
  CHECK((t2++).to_string() == "00:00:00");
}

TEST_CASE("++i")
{
  Time t1{21, 59, 59};
  Time t2{23, 59, 59};

  CHECK((++t1).to_string() == "21:59:59");
  CHECK_FALSE((++t1).to_string() == "22:00:00");
  CHECK((++t2).to_string() == "23:59:59");
  CHECK_FALSE((++t2).to_string() == "00:00:00");
}

TEST_CASE("i--")
{
  Time t1{22, 00, 00};
  Time t2{00, 00, 01};
  Time t3{00, 00, 00};

  CHECK((t1--).to_string() == "21:59:59");
  CHECK_FALSE((t1--).to_string() == "22:00:00");
  CHECK((t2--).to_string() == "00:00:00");
  CHECK_FALSE((t2--).to_string() == "00:00:01");
  CHECK((t3--).to_string() == "23:59:59");
  CHECK_FALSE((t3--).to_string() == "00:00:00");
}

TEST_CASE("--i")
{
  Time t1{22, 00, 00};
  Time t2{00, 00, 01};
  Time t3{00, 00, 00};

  CHECK_FALSE((--t1).to_string() == "21:59:59");
  CHECK((--t1).to_string() == "22:00:00");
  CHECK_FALSE((--t2).to_string() == "00:00:00");
  CHECK((--t2).to_string() == "00:00:01");
  CHECK_FALSE((--t3).to_string() == "23:59:59");
  CHECK((--t3).to_string() == "00:00:00");
}
//////////////////////////////////////////////////////////////////////////////
TEST_CASE ("Output operator" )
{
  stringstream ss;
  
  SECTION("Simple output")
  {
    ss << Time{2,5,1};
    CHECK(ss.str() == "02:05:01");
  }
  SECTION("Chained output")
  {
    ss << Time{23,10,32} << "---";
    CHECK(ss.str() == "23:10:32---");
  }
  SECTION("Const time")
  {
    Time const t{23,23,23};
    ss << t;
    CHECK(ss.str() == "23:23:23");
  }
}

TEST_CASE("Input operator" )
{
  Time t{};
  stringstream ss;
  
  SECTION("in-test")
  {
    ss << "02:20:31";
    ss >> t;
    CHECK(ss.str() == "02:20:31");
  }

  SECTION("Catch test h")
  {
    ss << "05:20:71";
    ss >> t;
    CHECK(ss.fail());
  }
}
