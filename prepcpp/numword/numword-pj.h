//
//  numword-pj.h
//  
//
//  Created by Prince Jain on 5/20/19.
//

#ifndef numword_pj_h
#define numword_pj_h

#include <string>
#include <map>
#include <iostream>

namespace bw {
    class numword{
        uint64_t _num;
        const std::map<int, std::string> _units{
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
        const std::map<int, std::string> _tenths{
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
        const std::map<int, std::string> _places{
            {0,""},
            {1,"thousand"},
            {2,"million"},
            {3,"billion"},
            {4,"trillion"},
            {5,"quadrillion"}
        };
        std::string getUnitMapping(const int & r);
        std::string getThousands(const int & n);
        std::string wordsHelper(const uint64_t & n, int place);

    public:
        numword();
        numword(const uint64_t &);//: _num(n){}
        uint64_t getn () const;
        void setn(const uint64_t & n);
        std::string words(const uint64_t & n);
        std::string words();
        ~numword();
        numword & operator = (const numword & rhs);
        std::string operator () (const uint64_t & n);
    };
}
#endif /* numword_pj_h */
