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
        static const std::map<int, std::string> _units;
        static const std::map<int, std::string> _tenths;
        static const std::map<int, std::string> _places;
        
        std::string getUnitMapping(const int & r);
        std::string getThousands(const int & n);
        std::string wordsHelper(const uint64_t & n, int place);

    public:
        numword(); // default constructor
        numword(const uint64_t &);
        numword(const numword & rhs); // copy constructor
        uint64_t getn () const; // get function
        void setn(const uint64_t & n); // set function
        std::string words(const uint64_t & n); // main utility to get the strings from number
        std::string words(); // same utility but taking default member num.
        ~numword(); // destructor
        numword & operator = (const numword & rhs); // copy operator
        std::string operator () (const uint64_t & n); // functor operator overloading
    };
}
#endif /* numword_pj_h */
