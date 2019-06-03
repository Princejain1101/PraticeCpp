//
//  PJString.cpp
//  
//
//  Created by Prince Jain on 6/1/19.
//
#include <algorithm>
#include "PJString.hpp"

PJString::PJString(){
    reset();
}
PJString::PJString(const char * ch){
    copy_str(ch);
}
PJString::PJString(const PJString & pjs){
    copy_str(pjs);
}
PJString::PJString(PJString && pjs) noexcept{
    reset();
    _str = std::move(pjs._str);
    pjs._str = nullptr;
    _str_size = std::move(pjs._str_size);
    pjs._str_size = 0;
    pjs.reset();
}
PJString::~PJString(){
    reset();
}


//data management
const char * PJString::alloc_str(size_t sz){
    reset();
    _str_size = std::min(sz, _pjstring_max_len);
    _str = new(std::nothrow) char[_str_size + 1]();
    if(_str == nullptr){
        printf("unable to allocate memory\n");
    }
    return _str;
}
void PJString::reset(){
    if(_str){
        delete [] _str;
        _str = nullptr;
        _str_size = 0;
    }
}
void PJString::swap(PJString & pjs){
    std::swap(pjs._str, _str);
    std::swap(pjs._str_size, _str_size);
}

const char * PJString::c_str() const{
    return _str;
}
const char * PJString::copy_str(const char * ch){
    if(ch){
        size_t len = strnlen(ch, _pjstring_max_len);
        if(alloc_str(len)){
            strncpy(_str, ch, len);
        }
    }
    return _str;
} // alloc and copy

// conversion operator
PJString::operator const char * () const{
    return this->c_str();
}

//operators
PJString & PJString::operator = (PJString pjs){
    copy_str(pjs);
    return *this;
}
PJString & PJString::operator += (const PJString & pjs){
    operator+=(pjs.c_str());
    return *this;
}
PJString & PJString::operator += (const char * ch){
    if(ch){
        size_t len = _str_size + strnlen(ch, _pjstring_max_len);
        if(len > _pjstring_max_len) len = _pjstring_max_len;
        
        size_t rhs_len = len - _str_size;
        if(rhs_len <= 0){
            return *this;
        }
        
        char * buffer = new char[len+1]();
        if(_str && _str_size) memcpy(buffer, _str, _str_size);
        memcpy(buffer + _str_size, ch, rhs_len);
        copy_str(buffer);
        delete [] buffer;
    }
    return *this;
}

const char PJString::operator [] (const int i) const {
    if(i >=0 && i < _str_size){
        return _str[i];
    }
    return 0;
}

PJString operator + (const PJString & lhs, const PJString & rhs){
    PJString res = lhs;
    res += rhs;
    return res;
}
//comparison
bool PJString::operator > (const PJString & pjs){
    if(std::strncmp(c_str(),pjs.c_str(),_pjstring_max_len) > 0) return true;
    else return false;
}
bool PJString::operator < (const PJString & pjs){
    if(std::strncmp(c_str(),pjs.c_str(),_pjstring_max_len) < 0) return true;
    else return false;
}
bool PJString::operator >= (const PJString & pjs){
    if(std::strncmp(c_str(),pjs.c_str(),_pjstring_max_len) >= 0) return true;
    else return false;
}
bool PJString::operator <= (const PJString & pjs){
    if(std::strncmp(c_str(),pjs.c_str(),_pjstring_max_len) <= 0) return true;
    else return false;
}
bool PJString::operator == (const PJString & pjs){
    if(std::strncmp(c_str(),pjs.c_str(),_pjstring_max_len) == 0) return true;
    else return false;
}
bool PJString::operator != (const PJString & pjs){
    if(std::strncmp(c_str(),pjs.c_str(),_pjstring_max_len) != 0) return true;
    else return false;
}

//utility
PJString PJString::lower() const{
    PJString res(*this);
    for(size_t i=0; _str[i]; i++){
        res._str[i] = tolower(_str[i]);
    }
    return res;
}
PJString PJString::upper() const{
    PJString res(*this);
    for(size_t i=0; _str[i]; i++){
        res._str[i] = toupper(_str[i]);
    }
    return res;
}
PJString & PJString::trim(){
    const static char * whitespace = "\x20\x1b\t\r\n\v\b\f\a";
    
    size_t begin = 0;
    size_t end = length() - 1;
    // reach beginning to first character.
    for(begin=0; begin <=end; begin++){
        if(strchr(whitespace, _str[begin]) == nullptr){
            break;
        }
    }
    for(; begin<end; end--){
        if(strchr(whitespace, _str[end]) == nullptr){
            break;
        }else{
            _str[end] = '\0';
        }
    }
    if(begin){
        for(size_t i=0; _str[i]; i++){
            _str[i] = _str[begin++];
        }
    }
    _str_size = strlen(_str);
    return *this;
}
const char PJString::front() const{
    if(_str){
        return _str[0];
    }else{
        return 0;
    }
}
const char PJString::back() const{
    if(_str){
        return _str[length()-1];
    }else{
        return 0;
    }
}
const bool PJString::is_empty() const{
    if(length()) return false;
    else return true;
}

// find and replace methods
long int PJString::char_find (const char & match){
    const char * f = strchr(_str, match);
    if(f == nullptr) return -1;
    else return f - _str;
}
PJString & PJString::char_repl (const char & match, const char & repl){
    long int pos = char_find(match);
    if(pos != -1) _str[pos] = repl;
    return *this;
}
PJString PJString::substr(size_t start, size_t length)const {
    PJString res;
    if(length + 1 > _pjstring_max_len) return res;
    
    if(_str && _str_size - start >= length){
        res.alloc_str(length+1);
        memcpy(res._str, _str + start, length);
    }
    return res;
}
long PJString::find(const PJString & match) const {
    size_t i=0;
    size_t j=0;
    size_t start=0;
    if((! _str) || (!match.c_str()))
        return -1;
    while(_str[i]){
        if(match._str[j]){
            if(_str[i] == match._str[j]){
                j++;
                i++;
            }else{
                j=0;
                i++;
                start = i;
            }
        } else {
            return start;
        }
    }
    return -1;
}
const PJString PJString::replace (const PJString & match, const PJString & repl){
    PJString res;
    size_t pos = find(match);
    if(pos >=0){
        PJString str1 = pos > 0 ? substr(0, pos) : "";
        size_t pos2 = pos + match.length();
        PJString str2 = substr(pos2, length() - pos2);
        res = str1 + repl + str2;
    }
    return res;
}
// private member function
void PJString::_reset_split_array() const {
    while(_split_count){
        _split_array[--_split_count].reset();
    }
    _split_array.reset();
    _split_count = 0;
}

void PJString::_append_split_array(const PJString & pjs) const {
    if(_split_count >= _max_splits) return;
    if(! _split_count){
        _split_array.reset(new _pjsp[_max_splits+1]);
    }
    _split_array[_split_count++] = std::make_shared<PJString>(pjs);
}

// public member functions

const PJString::split_ptr & PJString::split(const char *ch) const {
    return split(ch, -1);
}
const PJString::split_ptr & PJString::split(const char ch) const {
    const char chp[2] = {ch, 0};
    return split(chp, -1);
}

const PJString::split_ptr & PJString::split(const char *ch, int max_split) const {
    _reset_split_array();
    if(max_split < 0) max_split = _max_splits;
    
    if(length()<1) return _split_array;
    
    size_t max_len = strnlen(ch, _pjstring_max_len);
    if(max_len >= _pjstring_max_len) return _split_array;
    
    char * startp = _str;
    char * match;
    while((match = strstr(startp, ch)) && --max_split){
        std::cout<< startp<<std::endl;
        std::cout<< match<<std::endl;
        if(match != startp){
            size_t cp_len = match - startp;
            char * buffer = new char[cp_len + 1]();
            memcpy(buffer, startp, cp_len);
            _append_split_array(buffer);
            delete[] buffer;
            startp += cp_len;
        }
        startp += max_len;
    }
    if(startp[0] != '\0'){
        _append_split_array(startp);
    }
    return this->_split_array;
}

const PJString & PJString::split_item(size_t index) const {
    if(index < _split_count) return *(_split_array[index]);
    else return *this;
}


