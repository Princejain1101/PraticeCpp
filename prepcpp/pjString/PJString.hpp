//
//  PJString.hpp
//  
//
//  Created by Prince Jain on 6/1/19.
//

#ifndef PJString_hpp
#define PJString_hpp

#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cctype>
#include <memory>
#include <iostream>

constexpr size_t _pjstring_max_len = 65536;
constexpr size_t _max_splits = 1023;

class PJString {
    char * _str = nullptr;
    size_t _str_size = 0;
    
    typedef std::shared_ptr<PJString> _pjsp;
    typedef std::unique_ptr<_pjsp[]> _split_ptr;
    mutable _split_ptr _split_array;
    mutable size_t _split_count = 0;
    
    void _reset_split_array() const ;
    void _append_split_array(const PJString & pjs) const;
public:
    typedef _split_ptr split_ptr;
    // constructors
    PJString();
    PJString(const char * ch);
    PJString(const PJString & pjs);
    PJString(PJString && pjs) noexcept;
    ~PJString();
    
    //operators
    PJString & operator = (PJString pjs);
    PJString & operator += (const PJString & pjs);
    PJString & operator += (const char * ch);
    const char operator [] (const int i) const;
    //comparison
    bool operator > (const PJString & pjs);
    bool operator < (const PJString & pjs);
    bool operator >= (const PJString & pjs);
    bool operator <= (const PJString & pjs);
    bool operator == (const PJString & pjs);
    bool operator != (const PJString & pjs);
    
    //utility
    size_t length() const { return _str_size;}
    size_t size() const { return _str_size;}
    PJString lower() const;
    PJString upper() const;
    PJString & trim();
    const char front() const;
    const char back() const;
    const bool is_empty() const;
    
    //data management
    const char * alloc_str(size_t sz);
    void reset();
    void swap(PJString & pjs);
    const char * c_str() const;
    const char * copy_str(const char *); // alloc and copy
    
    // conversion operator
    operator const char * () const;
    
    // find and replace methods
    long int char_find (const char & match);
    PJString & char_repl (const char & match, const char & repl);
    PJString substr(size_t start, size_t length)const ;
    long find(const PJString & match) const ;
    const PJString replace (const PJString & match, const PJString & repl);
    
    // split methods
    const split_ptr & split(const char * ch) const ;
    const split_ptr & split(const char ch) const ;
    const split_ptr & split(const char * ch, int max_split) const ;
    const PJString & split_item(size_t index)const;
    size_t split_count() const { return _split_count;}
};
PJString operator + (const PJString & lhs, const PJString & rhs);

#endif /* PJString_hpp */
