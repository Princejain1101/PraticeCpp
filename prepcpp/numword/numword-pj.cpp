//
//  numword-pj.cpp
//  
//
//  Created by Prince Jain on 5/21/19.
//

#include <stdio.h>
#include "numword-pj.h"

using namespace bw;

const std::map<int, std::string> numword::_units{
    {1,"one"},
    {2,"two"},
    {3,"three"},
    {4,"four"},
    {5,"five"},
    {6,"six"},
    {7,"seven"},
    {8,"eight"},
    {9,"nine"}
};
const std::map<int, std::string> numword::_tenths{
    {10,"ten"},
    {11,"eleven"},
    {12,"twelve"},
    {13,"thirteen"},
    {14,"fourteen"},
    {15,"fifteen"},
    {16,"sixteen"},
    {17,"seventeen"},
    {18,"eighteen"},
    {19,"nineteen"},
    {2,"twenty"},
    {3,"thirty"},
    {4,"fourty"},
    {5,"fifty"},
    {6,"sixty"},
    {7,"seventy"},
    {8,"eighty"},
    {9,"ninety"}
};
const std::map<int, std::string> numword::_places{
    {0,""},
    {1,"thousand"},
    {2,"million"},
    {3,"billion"},
    {4,"trillion"},
    {5,"quadrillion"}
};
numword::numword(): _num(0){}

numword::numword(const uint64_t & n): _num(n){}

numword::numword(const numword & rhs): _num(rhs._num){}

uint64_t numword::getn () const { return _num;}

numword::~numword(){}

numword & numword::operator = (const numword & rhs){
    this->_num = rhs._num;
    return *this;
}

std::string numword::operator () (const uint64_t & n){
    return words(n);
}

void numword::setn(const uint64_t & n) {
    _num = n;
}

std::string numword::words(){
    return words(_num);
}

std::string numword::getThousands(const int & thousand){
    std::string ret = "";
    int third = (int)thousand / 100;
    if(third > 0 && third < 10){
        ret = ret + _units.at(third) + " hundred";
    }
    if(third == 10){
        return "";
    }
    int hundreds = (int)thousand % 100;
    if(hundreds > 0){
        if(third > 0) ret = ret + " ";
        int second = hundreds / 10;
        if(second == 1){
            ret = ret + _tenths.at(hundreds);
        }
        if(second > 1){
            ret  = ret + _tenths.at(second);
            auto ones = hundreds % 10;
            if(ones > 0){
                ret = ret + "-" + _units.at(ones);
            }
        }
        if(second == 0){
            auto ones = hundreds % 10;
            if(ones > 0){
                ret = ret + _units.at(ones);
            }
        }
    }
    return ret;
}

std::string numword::words(const uint64_t & n){
    return wordsHelper(n, 0);
}

std::string numword::wordsHelper(const uint64_t & n, int place){
    if(n <= 0){
        return "";
    }
    if(place >= 6){
        return "error";
    }
    std::string ret = wordsHelper(n / 1000, place + 1);
    if(ret == "error"){
        return ret;
    }
    int thousands = n % 1000;
    if(ret != "" && getThousands(thousands) != "") ret = ret + " " + getThousands(thousands);
    else ret = ret + getThousands(thousands);
    
    if(place > 0 && getThousands(thousands) != ""){
        ret = ret + " " + _places.at(place);
    }
    //std::cout<<ret<<std::endl;
    return ret;
    }
