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
            NumberWithUnits(double num, const string &str);
            NumberWithUnits& operator+=(const NumberWithUnits &b);
            NumberWithUnits& operator-=(const NumberWithUnits &b);      
    };

    NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b);
    NumberWithUnits operator+(const NumberWithUnits &a);
    NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b);
    NumberWithUnits operator-(const NumberWithUnits &a);
    bool operator>(const NumberWithUnits &a, const NumberWithUnits &b);
    bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b);
    bool operator<(const NumberWithUnits &a, const NumberWithUnits &b);
    bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b);
    bool operator==(const NumberWithUnits &a, const NumberWithUnits &b);
    bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b);
    NumberWithUnits &operator++(NumberWithUnits &a);
    NumberWithUnits operator++(NumberWithUnits &a, int);
    NumberWithUnits &operator--(NumberWithUnits &a);
    NumberWithUnits operator--(NumberWithUnits &a, int);
    NumberWithUnits operator*(const double num, const NumberWithUnits &a);
    NumberWithUnits operator*(const NumberWithUnits &a, const double num);
    NumberWithUnits operator*(const NumberWithUnits &a, const NumberWithUnits &b);
    ostream &operator<<(ostream &out, const NumberWithUnits &a);
    istream &operator>>(istream &in, NumberWithUnits &a);
    
}