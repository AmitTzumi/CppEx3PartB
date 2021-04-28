#include "NumberWithUnits.hpp"

using namespace std;

namespace ariel{

    void NumberWithUnits::read_units(ifstream &units_file){
        string text;
        while(getline(units_file, text)){
            //cout << text << endl;
            string word = "";
            for (auto x : text) 
            {
                if (x == ' ')
                {
                    if(word != "="){
                        if(word!= "1"){
                            cout << word << endl;
                        }
                    //word = word.substr(0, word.length() - 1);    
                    }
                    word = "";
                }
                else {
                    word = word + x;
                }
            }
            cout << word << endl;
        }
    }

    string check_type(NumberWithUnits a, NumberWithUnits b){
        if((a.type == "km" && (b.type == "km" || b.type == "m" || b.type == "cm")) || 
        (a.type == "m" && (b.type == "km" || b.type == "m" || b.type == "cm")) ||
        (a.type == "cm" && (b.type == "km" || b.type == "m" || b.type == "cm"))){
            return "distance";
        }
        
        if((a.type == "ton" && (b.type == "ton" || b.type == "kg" || b.type == "g")) ||
        (a.type == "kg" && (b.type == "ton" || b.type == "kg" || b.type == "g")) ||
        (a.type == "g" && (b.type == "ton" || b.type == "kg" || b.type == "g"))){
            return "size";
        }
        
        if((a.type == "hour" && (b.type == "hour" || b.type == "min" || b.type == "sec")) || 
        (a.type == "min" && (b.type == "hour" || b.type == "min" || b.type == "sec")) ||
        (a.type == "sec" && (b.type == "hour" || b.type == "min" || b.type == "sec"))){
            return "time";
        }
        
        if((a.type == "USD" && (b.type == "USD" || b.type == "ILS")) ||
        (a.type == "ILS" && (b.type == "USD" || b.type == "ILS"))){
            return "money";
        }
        return "false";
    }

    NumberWithUnits operator+(NumberWithUnits a, NumberWithUnits b){
        //NumberWithUnits c(0,NULL);
        /*if(check_type(a,b) == "false"){
            throw invalid_argument("These two numbers are of different dimensions and are not connectable.");
        }
        else{
            if(check_type(a,b) == "distance"){
                if(a.type == "km" && b.type == "km"){
                   c.unit = a.unit + b.unit;
                   c.type = "km";
                }
                if(a.type == "km" && b.type == "m"){
                    c.unit = a.unit * 1000 + b.unit;
                    c.unit = c.unit/1000;
                    c.type = "km";
                }
                if(a.type == "km" && b.type == "cm"){
                    c.unit = a.unit * 1000 + b.unit/100;
                    c.unit = c.unit/1000;
                    c.type = "km";
                }
                if(a.type == "m" && b.type == "km"){
                   c.unit = a.unit + b.unit*1000;
                   c.type = "m";
                }
                if(a.type == "m" && b.type == "m"){
                    c.unit = a.unit + b.unit;
                    c.type = "m";
                }
                if(a.type == "m" && b.type == "cm"){
                    c.unit = a.unit + b.unit/100;
                    c.type = "m";
                }
                if(a.type == "cm" && b.type == "km"){
                   c.unit = a.unit + b.unit*100000;
                   c.type = "cm";
                }
                if(a.type == "cm" && b.type == "m"){
                    c.unit = a.unit + b.unit*100;
                    c.type = "cm";
                }
                if(a.type == "cm" && b.type == "cm"){
                    c.unit = a.unit + b.unit;
                    c.type = "cm";
                }
            }

            if(check_type(a,b) == "size"){
                if(a.type == "ton" && b.type == "ton"){
                   c.unit = a.unit + b.unit;
                   c.type = "ton";
                }
                if(a.type == "ton" && b.type == "kg"){
                    c.unit = a.unit * 1000 + b.unit;
                    c.unit = c.unit/1000;
                    c.type = "ton";
                }
                if(a.type == "ton" && b.type == "g"){
                    c.unit = a.unit * 1000 + b.unit/1000;
                    c.unit = c.unit/1000;
                    c.type = "ton";
                }
                if(a.type == "kg" && b.type == "ton"){
                   c.unit = a.unit + b.unit*1000;
                   c.type = "kg";
                }
                if(a.type == "kg" && b.type == "kg"){
                    c.unit = a.unit + b.unit;
                    c.type = "kg";
                }
                if(a.type == "kg" && b.type == "g"){
                    c.unit = a.unit + b.unit/1000;
                    c.type = "kg";
                }
                if(a.type == "g" && b.type == "ton"){
                   c.unit = a.unit + b.unit*1000000;
                   c.type = "g";
                }
                if(a.type == "g" && b.type == "kg"){
                    c.unit = a.unit + b.unit*1000;
                    c.type = "g";
                }
                if(a.type == "g" && b.type == "g"){
                    c.unit = a.unit + b.unit;
                    c.type = "g";
                }
            }

            if(check_type(a,b) == "time"){
                if(a.type == "hour" && b.type == "hour"){
                   c.unit = a.unit + b.unit;
                   c.type = "hour";
                }
                if(a.type == "hour" && b.type == "min"){
                    c.unit = a.unit * 60 + b.unit;
                    c.unit = c.unit/60;
                    c.type = "hour";
                }
                if(a.type == "hour" && b.type == "sec"){
                    c.unit = a.unit * 60 + b.unit/60;
                    c.unit = c.unit/60;
                    c.type = "hour";
                }
                if(a.type == "min" && b.type == "hour"){
                   c.unit = a.unit + b.unit*60;
                   c.type = "min";
                }
                if(a.type == "min" && b.type == "min"){
                    c.unit = a.unit + b.unit;
                    c.type = "min";
                }
                if(a.type == "min" && b.type == "sec"){
                    c.unit = a.unit + b.unit/60;
                    c.type = "min";
                }
                if(a.type == "sec" && b.type == "hour"){
                   c.unit = a.unit + b.unit*60*60;
                   c.type = "sec";
                }
                if(a.type == "sec" && b.type == "min"){
                    c.unit = a.unit + b.unit*60;
                    c.type = "sec";
                }
                if(a.type == "sec" && b.type == "sec"){
                    c.unit = a.unit + b.unit;
                    c.type = "sec";
                }
            }

            if(check_type(a,b) == "money"){
                if(a.type == "USD" && b.type == "USD"){
                   c.unit = a.unit + b.unit;
                   c.type = "USD";
                }
                if(a.type == "USD" && b.type == "ILS"){
                    c.unit = a.unit  + b.unit/3.33;
                    c.type = "USD";
                }
                if(a.type == "ILS" && b.type == "USD"){
                    c.unit = a.unit  + b.unit*3.33;
                    c.type = "ILS";
                }
                if(a.type == "ILS" && b.type == "ILS"){
                   c.unit = a.unit + b.unit;
                   c.type = "ILS";
                }
            }
        }*/
        return a;
    }

    NumberWithUnits operator+=(NumberWithUnits a, NumberWithUnits b){
        /*if(check_type(a,b) == "false"){
            throw invalid_argument("These two numbers are of different dimensions and are not connectable.");
        }
        else{
            if(check_type(a,b) == "distance"){
                if(a.type == "km" && b.type == "km"){
                   a.unit += b.unit;
                }
                if(a.type == "km" && b.type == "m"){
                    a.unit = a.unit * 1000 + b.unit;
                    a.unit = a.unit/1000;
                }
                if(a.type == "km" && b.type == "cm"){
                    a.unit = a.unit * 1000 + b.unit/100;
                    a.unit = a.unit/1000;
                }
                if(a.type == "m" && b.type == "km"){
                   a.unit = a.unit + b.unit*1000;
                }
                if(a.type == "m" && b.type == "m"){
                    a.unit = a.unit + b.unit;
                }
                if(a.type == "m" && b.type == "cm"){
                    a.unit = a.unit + b.unit/100;
                }
                if(a.type == "cm" && b.type == "km"){
                   a.unit = a.unit + b.unit*100000;
                }
                if(a.type == "cm" && b.type == "m"){
                    a.unit = a.unit + b.unit*100;
                }
                if(a.type == "cm" && b.type == "cm"){
                    a.unit = a.unit + b.unit;
                }
            }

            if(check_type(a,b) == "size"){
                if(a.type == "ton" && b.type == "ton"){
                   a.unit = a.unit + b.unit;
                }
                if(a.type == "ton" && b.type == "kg"){
                    a.unit = a.unit * 1000 + b.unit;
                    a.unit = a.unit/1000;
                }
                if(a.type == "ton" && b.type == "g"){
                    a.unit = a.unit * 1000 + b.unit/1000;
                    a.unit = a.unit/1000;
                }
                if(a.type == "kg" && b.type == "ton"){
                   a.unit = a.unit + b.unit*1000;
                }
                if(a.type == "kg" && b.type == "kg"){
                    a.unit = a.unit + b.unit;
                }
                if(a.type == "kg" && b.type == "g"){
                    a.unit = a.unit + b.unit/1000;
                }
                if(a.type == "g" && b.type == "ton"){
                   a.unit = a.unit + b.unit*1000000;
                }
                if(a.type == "g" && b.type == "kg"){
                    a.unit = a.unit + b.unit*1000;
                }
                if(a.type == "g" && b.type == "g"){
                    a.unit = a.unit + b.unit; 
                }
            }

            if(check_type(a,b) == "time"){
                if(a.type == "hour" && b.type == "hour"){
                   a.unit = a.unit + b.unit;
                }
                if(a.type == "hour" && b.type == "min"){
                    a.unit = a.unit * 60 + b.unit;
                    a.unit = a.unit/60;
                }
                if(a.type == "hour" && b.type == "sec"){
                    a.unit = a.unit * 60 + b.unit/60;
                    a.unit = a.unit/60;
                }
                if(a.type == "min" && b.type == "hour"){
                   a.unit = a.unit + b.unit*60;
                }
                if(a.type == "min" && b.type == "min"){
                    a.unit = a.unit + b.unit;
                }
                if(a.type == "min" && b.type == "sec"){
                    a.unit = a.unit + b.unit/60;
                }
                if(a.type == "sec" && b.type == "hour"){
                   a.unit = a.unit + b.unit*60*60;
                }
                if(a.type == "sec" && b.type == "min"){
                    a.unit = a.unit + b.unit*60;
                }
                if(a.type == "sec" && b.type == "sec"){
                    a.unit = a.unit + b.unit;
                }
            }

            if(check_type(a,b) == "money"){
                if(a.type == "USD" && b.type == "USD"){
                   a.unit = a.unit + b.unit;
                }
                if(a.type == "USD" && b.type == "ILS"){
                    a.unit = a.unit  + b.unit/3.33;
                }
                if(a.type == "ILS" && b.type == "USD"){
                    a.unit = a.unit  + b.unit*3.33; 
                }
                if(a.type == "ILS" && b.type == "ILS"){
                   a.unit = a.unit + b.unit;
                }
            }
            return a;
        }*/
        return a;
    }

    NumberWithUnits operator+(NumberWithUnits a){
        return a;
    }

    NumberWithUnits operator-(NumberWithUnits a, NumberWithUnits b){
        return a;
    }

    NumberWithUnits operator-=(NumberWithUnits a, NumberWithUnits b){
        return a;
    }

    NumberWithUnits operator-(NumberWithUnits a){
        return a;
    }

    bool operator>(NumberWithUnits a, NumberWithUnits b){
        return true;
    }

    bool operator>=(NumberWithUnits a, NumberWithUnits b){
        return true;
    }

    bool operator<(NumberWithUnits a, NumberWithUnits b){
        return true;
    }

    bool operator<=(NumberWithUnits a, NumberWithUnits b){
        return true;
    }

    bool operator==(NumberWithUnits a, NumberWithUnits b){
        return true;
    }

    bool operator!=(NumberWithUnits a, NumberWithUnits b){
        return true;
    }

    NumberWithUnits operator++(NumberWithUnits a){
        return a;
    }

    NumberWithUnits operator--(NumberWithUnits a){
        return a;
    }

    NumberWithUnits operator*(double num, NumberWithUnits a){
        return a;
    }

    ostream& operator<<(ostream& out, NumberWithUnits a){
        return out;
    }

    istream& operator>>(istream& in, NumberWithUnits a){
        return in;
    }

}