#include "NumberWithUnits.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace ariel;
namespace ariel
{        
        void ariel::NumberWithUnits::read_units(ifstream& units_file){
            
        }

        std::ostream& operator << (ostream& os, const NumberWithUnits& unit_R){
                os << unit_R.amount << "[" << unit_R.type << "]";
                return os;

        }
        std::istream& operator >> (istream& is, NumberWithUnits& unit_R){
                char ch = '[';
                char hc = ']';
                is >> unit_R.re >> ch >> unit_R.type >> hc;
                return is;
        }



        bool operator > (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){return true;}
        bool operator >= (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){return true;}

        bool operator < (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){return true;}
        bool operator <= (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){return true;}

        bool operator == (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){return true;}
        bool operator != (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){return true;}

        NumberWithUnits operator + (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){
                return NumberWithUnits(unit_R.amount+unit_L.amount,unit_L.type);
        }
        NumberWithUnits operator + (const NumberWithUnits& unit_L, double a){
                return NumberWithUnits(unit_L.amount+a,unit_L.type);
        }
        NumberWithUnits operator += (NumberWithUnits& unit_L, const NumberWithUnits& unit_R){
                return NumberWithUnits(unit_R.amount+unit_L.amount,unit_L.type);
        }
        NumberWithUnits operator += (NumberWithUnits& unit_L, double num){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }
        NumberWithUnits operator += (NumberWithUnits& unit_L, int num){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }


        NumberWithUnits operator - (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R){
                return NumberWithUnits(unit_R.amount-unit_L.amount,unit_L.type);
        }
        NumberWithUnits operator - (const NumberWithUnits& unit_L, double num){
                return NumberWithUnits(unit_L.amount*num,unit_L.type);   
        }
        NumberWithUnits operator - (const NumberWithUnits& unit_L){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }
        NumberWithUnits operator -= (NumberWithUnits& unit_L, const NumberWithUnits& unit_R){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }

        NumberWithUnits operator ++ (NumberWithUnits& unit_L){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }
        NumberWithUnits operator ++ (NumberWithUnits& unit_L, int){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }

        NumberWithUnits operator -- (NumberWithUnits& unit_L){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }
        NumberWithUnits operator -- (NumberWithUnits& unit_L, int){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }

        NumberWithUnits operator * (NumberWithUnits& unit_L, double num){
                return NumberWithUnits(unit_L.amount*num,unit_L.type);
        }
        NumberWithUnits operator *= (NumberWithUnits& unit_L, double num){
                return NumberWithUnits(-unit_L.amount,unit_L.type);
        }

        NumberWithUnits operator * (double num, NumberWithUnits& unit_R){
                return NumberWithUnits(unit_R.amount*num,unit_R.type);
        }
        NumberWithUnits operator *= (double num, NumberWithUnits& unit_R){
                return NumberWithUnits(-unit_R.amount,unit_R.type);
        }
        
} // namespace ariel
        

