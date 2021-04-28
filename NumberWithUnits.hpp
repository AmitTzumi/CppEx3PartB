#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel{
    class NumberWithUnits{
        public:
        double unit;
        string type;

        static void read_units(ifstream &units_file);
        NumberWithUnits(double num, string str){
            unit = num;
            type =str;
        }
    };
    string check_type(NumberWithUnits a, NumberWithUnits b);
    NumberWithUnits operator+(NumberWithUnits a, NumberWithUnits b);
    NumberWithUnits operator+=(NumberWithUnits a, NumberWithUnits b);
    NumberWithUnits operator+(NumberWithUnits a);
    NumberWithUnits operator-(NumberWithUnits a, NumberWithUnits b);
    NumberWithUnits operator-=(NumberWithUnits a, NumberWithUnits b);
    NumberWithUnits operator-(NumberWithUnits a);
    bool operator>(NumberWithUnits a, NumberWithUnits b);
    bool operator>=(NumberWithUnits a, NumberWithUnits b);
    bool operator<(NumberWithUnits a, NumberWithUnits b);
    bool operator<=(NumberWithUnits a, NumberWithUnits b);
    bool operator==(NumberWithUnits a, NumberWithUnits b);
    bool operator!=(NumberWithUnits a, NumberWithUnits b);
    NumberWithUnits operator++(NumberWithUnits a);
    NumberWithUnits operator--(NumberWithUnits a);
    NumberWithUnits operator*(double num, NumberWithUnits a);
    ostream& operator<<(ostream& out, NumberWithUnits a);
    istream& operator>>(istream& in, NumberWithUnits a);

}