#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace ariel;
using namespace std;

/*

1 km = 1000 m
1 m = 100 cm

1 kg = 1000 g
1 ton = 1000 kg

1 hour = 60 min
1 min = 60 sec

1 USD = 3.33 ILS

*/

/*
    READ PLEASE ############################################### 
    
    IF YOU AN OUTPUT IN YOUR DESTRUCTOR - I RECOMMEND TO DISABLE IT JUST FOR THE TEST
    
    ############################################### READ PLEASE
*/

ifstream units_file{"units.txt"};
const double TOLERANCE = 0.0000003;

TEST_CASE("Initiated"){
    ariel::NumberWithUnits::read_units(units_file); 

        NumberWithUnits u_km{1, "km"};
        NumberWithUnits u_m(1, "m");
        NumberWithUnits u_cm(1, "cm");

        NumberWithUnits u_g(1, "g");
        NumberWithUnits u_kg(1, "kg");
        NumberWithUnits u_ton(1, "ton");

        NumberWithUnits u_hour(1, "hour");
        NumberWithUnits u_min(1, "min");
        NumberWithUnits u_sec(1, "sec");

        NumberWithUnits u_USD(1.0, "USD");
        NumberWithUnits u_LIS(1.0, "LIS");

    SUBCASE("Stage 1: Checking all units"){
  
        CHECK(u_km  == 100*u_m);  
        CHECK((-u_km) == -100*u_m); 

        CHECK(u_m == 100*u_cm); 
        CHECK((-u_m) == -100*u_cm); 

        CHECK(u_cm == 1*u_cm); 
        CHECK((-u_cm) == -1*u_cm); 

        CHECK(u_g == 1*u_g); 
        CHECK((-u_g) == -1*u_g); 

        CHECK(u_kg == 1000*u_g); 
        CHECK((-u_kg) == -1000*u_g); 

        CHECK(u_ton == 1000*u_kg); 
        CHECK((-u_ton) == -1000*u_kg); 

        CHECK(u_hour == 60*u_min); 
        CHECK((-u_hour) == -60*u_min); 

        CHECK(u_min == 60*u_sec); 
        CHECK((-u_min) == -60*u_sec); 

        CHECK(u_sec == 1*u_sec); 
        CHECK((-u_sec) == -1*u_sec); 

        CHECK(u_USD == (3.33)*u_LIS); 
        CHECK((-u_USD) == -(3.33)*u_LIS); 

        CHECK(u_LIS == 1*u_LIS); 
        CHECK((-u_LIS) == -(1)*u_LIS);   
    }

    SUBCASE("Stage 2: += Rvalue -> int,double"){
        
        for (int i = 0; i < 1000; i++)
        {
            u_cm += 1;
        }
        CHECK(u_cm == 10*u_m);

        for (int i = 0; i < 1000; i++)
        {
            u_m += 1;
        }
        CHECK(u_m == u_km);

        NumberWithUnits u_cmS(1, "cm");

        for (int i = 0; i < 100000; i++)
        {
            u_cmS += 1;
        }
        CHECK(u_cmS == u_km);

        for (int i = 0; i < 1000; i++)
        {
            u_g += 1;
        }
        CHECK(u_g == u_kg);

        for (int i = 0; i < 1000; i++)
        {
            u_kg += 1;
        }
        CHECK(u_kg == u_ton);

        NumberWithUnits u_gS(1, "g");

        for (int i = 0; i < 10000; i++)
        {
            u_gS += 1;
        }
        CHECK(u_gS == u_ton);

        for (int i = 0; i < 60; i++)
        {
            u_sec += 1;
        }
        CHECK(u_sec == u_min);

        for (int i = 0; i < 60; i++)
        {
            u_min += 1;
        }
        CHECK(u_min == u_hour);

        NumberWithUnits u_secS(1, "sec");

        for (int i = 0; i < 3600; i++)
        {
            u_secS += 1;
        }
        CHECK(u_secS == u_hour);


        CHECK(u_LIS+(2.33) == u_USD);

        for (size_t i = 0; i < 10; i++)
        {
            u_LIS += 3.33;
        }

        NumberWithUnits u_USDs(TOLERANCE, "USD");

        CHECK( (u_LIS - u_USD) >= u_USDs);
        
    
    }    
    SUBCASE("Stage 3 : += Rvalue -> Object "){
        
        NumberWithUnits u_append_m(1, "m");
        NumberWithUnits u_append_cm(1, "cm");

        for (int i = 0; i < 1000; i++)
        {
            u_cm += u_append_cm;
        }
        CHECK(u_cm == 10*u_m);

        for (int i = 0; i < 1000; i++)
        {
            u_m += u_append_m;
        }
        CHECK(u_m == u_km);

        NumberWithUnits u_cmS(1, "cm");
        
        for (int i = 0; i < 100000; i++)
        {
            u_cmS += u_append_cm;
        }
        CHECK(u_cmS == u_km);

        NumberWithUnits u_append_g(1, "g");
        NumberWithUnits u_append_kg(1, "kg");

        for (int i = 0; i < 1000; i++)
        {
            u_g += u_append_g;
        }
        CHECK(u_g == u_kg);

        for (int i = 0; i < 1000; i++)
        {
            u_kg += u_append_kg;
        }
        CHECK(u_kg == u_ton);

        NumberWithUnits u_gS(1, "g");

        for (int i = 0; i < 10000; i++)
        {
            u_gS += u_append_g;
        }
        CHECK(u_gS == u_ton);

        NumberWithUnits u_append_min(1, "min");

        NumberWithUnits u_append_sec(1, "sec");

        for (int i = 0; i < 60; i++)
        {
            u_sec += u_append_sec;
        }
        CHECK(u_sec == u_min);

        for (int i = 0; i < 60; i++)
        {
            u_min += u_append_min;
        }
        CHECK(u_min == u_hour);

        NumberWithUnits u_secS(1, "sec");

        for (int i = 0; i < 3600; i++)
        {
            u_secS += u_append_sec;
        }
        CHECK(u_secS == u_hour);

        NumberWithUnits u_append_USD(1.0, "USD");

        CHECK(u_LIS+(2.33) == u_USD);

        for (size_t i = 0; i < 10; i++)
        {
            u_LIS += u_append_USD;
        }

        NumberWithUnits u_USDs(TOLERANCE, "USD");
        CHECK( (u_LIS - u_USD) >= u_USDs);

    }

}
