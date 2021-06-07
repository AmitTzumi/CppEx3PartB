#include "NumberWithUnits.hpp"
#include <map>
#include <cstdlib>
using namespace std;

namespace ariel{

    const double EPSILON = 0.00001; 
    static map<string, map<string, double>> units_map;

    NumberWithUnits::NumberWithUnits(double unit, const string &type)
    {
        units_map.at(type); 
        this->unit = unit;
        this->type = type;
    }

    void NumberWithUnits::read_units(ifstream &units_file){
        string type1, type2, equal;
        double unit1 = 0, unit2 = 0;

        while (units_file >> unit1 >> type1 >> equal >> unit2 >> type2)
        {
            units_map[type1][type2] = unit2;
            units_map[type2][type1] = unit1 / unit2;
            for (auto &connected_type : units_map[type1])
            {
                double connected_val = units_map[type2][type1] * connected_type.second;
                units_map[type2][connected_type.first] = connected_val;
                units_map[connected_type.first][type2] = 1 / connected_val;
            }
            for (auto &connected_type : units_map[type2])
            {
                double connected_val = units_map[type1][type2] * connected_type.second;
                units_map[type1][connected_type.first] = connected_val;
                units_map[connected_type.first][type1] = 1 / connected_val;
            }
        }
    }

    double check_type_convert(double value, const string &type1,const string &type2)
    {
        if (units_map[type1].count(type2) == 0){
            throw invalid_argument("Can not convert this two types");
        } 
        if (type1 == type2){
            return value;
        }
        return value * units_map[type1][type2];
    }

    NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b){
        double plus_bin = check_type_convert(b.unit, b.type, a.type);
        NumberWithUnits temp(plus_bin + a.unit, a.type);
        return temp;
    }
        
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits &b){
         this->unit += check_type_convert(b.unit, b.type, this->type);
        return *this;
    }    

    NumberWithUnits operator+(const NumberWithUnits &a){
        NumberWithUnits temp(+a.unit,a.type);
        return temp;
    }

    NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b){
        double minus_bin = check_type_convert(b.unit, b.type, a.type);
        NumberWithUnits temp(a.unit- minus_bin, a.type);
        return temp;
    }

    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits &b){
        this->unit -= check_type_convert(b.unit, b.type, this->type);
        return *this;
    }

    NumberWithUnits operator-(const NumberWithUnits &a){
       NumberWithUnits temp(-a.unit,a.type);
        return temp;
    }

    bool operator>(const NumberWithUnits &a, const NumberWithUnits &b){
        return a.unit > check_type_convert(b.unit,b.type,a.type);
    }

    bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b){
        double greater_equ = check_type_convert(b.unit,b.type,a.type);
        return a.unit > greater_equ || abs(a.unit-greater_equ) < EPSILON;
    }

    bool operator<(const NumberWithUnits &a, const NumberWithUnits &b){
        return a.unit < check_type_convert(b.unit,b.type,a.type);
    }

    bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b){
        double smaller_equ = check_type_convert(b.unit,b.type,a.type);
        return a.unit < smaller_equ || abs(a.unit-smaller_equ) < EPSILON;
    }

    bool operator==(const NumberWithUnits &a, const NumberWithUnits &b){
        return abs(a.unit-check_type_convert(b.unit,b.type,a.type)) < EPSILON;
    }

    bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b){
        return a.unit != check_type_convert(b.unit,b.type,a.type);
    }

    NumberWithUnits &operator++(NumberWithUnits &a){
        a.unit++;
        return a;;
    }

    NumberWithUnits operator++(NumberWithUnits &a, int)
    {
        NumberWithUnits temp(a.unit++,a.type);
        return temp;
    }

    NumberWithUnits &operator--(NumberWithUnits &a){
        a.unit--;
        return a;
    }

    NumberWithUnits operator--(NumberWithUnits &a, int){
        NumberWithUnits temp(a.unit--,a.type);
        return temp;
    }

    NumberWithUnits operator*(double num, const NumberWithUnits &a){
        return NumberWithUnits(a.unit*num, a.type);
    }

    NumberWithUnits operator*(const NumberWithUnits &a, double num){
        return NumberWithUnits(a.unit*num, a.type);
    }

    NumberWithUnits operator*(const NumberWithUnits &a,const NumberWithUnits &b)
    {
        double unit_mul = check_type_convert(b.unit,a.type,b.type);
        NumberWithUnits temp(a.unit*unit_mul, a.type);
        return temp;
    }

    ostream& operator<<(ostream& out, const NumberWithUnits &a){
        return out << a.unit << "[" << a.type << "]";
    }

    istream& operator>>(istream& in, NumberWithUnits &a){
        double value = 0;
        string type;
        in >> value;
        char temp = ' ';
        bool flag = false;
        while(temp!=']'){
            if(temp=='['){
                flag = true;
            }
            in >> temp;
            if(flag){
                if(temp != ' ' && temp != ']') {
                    type += temp;
                }
            }
        }
        if(units_map.count(type)==0)
        {
            throw invalid_argument("type is not in the units map");
        }
        a.type = type;
        a.unit = value;
        return in;
    }

}