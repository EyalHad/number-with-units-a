#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel {

    class NumberWithUnits
    {
    private:
        double re;
        int amount;
        string type;
    public:
        NumberWithUnits(int amount,string type){
            this->amount = amount;
            this->type = type;
        }
        NumberWithUnits(double amount,string type){
            re = amount;
            this->type = type;
        }
        ~NumberWithUnits(){
            // cout << "Deleted:  -> " << this->amount << "[" << this->type << "]" << endl;
        }


        static void read_units(ifstream& units_file);

        /*
            Most operators need massive changes 

            This is just for "error free" at compilation
        */

        friend NumberWithUnits operator + (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);
        friend NumberWithUnits operator + (const NumberWithUnits& unit_L, double num);
        friend NumberWithUnits operator += (NumberWithUnits& unit_L, const NumberWithUnits& unit_R);
        friend NumberWithUnits operator += (NumberWithUnits& unit_L, double num);
        friend NumberWithUnits operator += (NumberWithUnits& unit_L, int num);


        friend NumberWithUnits operator - (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);
        friend NumberWithUnits operator - (const NumberWithUnits& unit_L);
        friend NumberWithUnits operator - (const NumberWithUnits& unit_L, double num);
        friend NumberWithUnits operator -= (NumberWithUnits& unit_L, const NumberWithUnits& unit_R);

        friend NumberWithUnits operator ++ (NumberWithUnits& unit_L);
        friend NumberWithUnits operator ++ (NumberWithUnits& unit_L, int);

        friend NumberWithUnits operator -- (NumberWithUnits& unit_L);
        friend NumberWithUnits operator -- (NumberWithUnits& unit_L, int);

        friend NumberWithUnits operator * (NumberWithUnits& unit_L, double num);
        friend NumberWithUnits operator *= (NumberWithUnits& unit_L, double num);

        friend NumberWithUnits operator * (double num, NumberWithUnits& unit_R);
        friend NumberWithUnits operator *= (double num, NumberWithUnits& unit_R);



        friend bool operator > (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);
        friend bool operator >= (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);

        friend bool operator < (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);
        friend bool operator <= (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);

        friend bool operator == (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);
        friend bool operator != (const NumberWithUnits& unit_L, const NumberWithUnits& unit_R);

        /* 
        >>---------------------------->>
            friend global IO operators
        <<----------------------------<<
        */
        // need to add 
        friend ostream& operator << (ostream& os, const NumberWithUnits& unit_R);
        friend istream& operator >> (istream& is, NumberWithUnits& unit_R);
    };

}