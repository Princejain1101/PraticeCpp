//
//  expressiveWords.hpp
//  leetcode
//
//  Created by Prince Jain on 6/9/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef expressiveWords_hpp
#define expressiveWords_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric> // iota

using namespace std;

class Solution {
    void _setWords(vector<string>& words, vector<int> &pointers, int count, char c){
        std::cout<<"count: "<<count<<",char: "<<c<<std::endl;
        for(int i=0; i<pointers.size() ; i++){
            int pos = pointers[i];
            for(int j=1; j<=count; j++){
                if(pos != -1 || pos < words[i].size()){
                    if(words[i][pos] == c){
                        pos++;
                    }else if(count == 1 || count == 2){
                        std::cout<<"removing: "<<words[i]<<std::endl;
                        pos = -1;//(int)words[i].size()+1;
                        break;
                    }else{
                        break;
                    }
                }else if(count == 1 || count == 2){
                    std::cout<<"removing: "<<words[i]<<" with short length"<<std::endl;
                    pos= -1;
                    break;
                }else{
                    break;
                }
            }
            pointers[i] = pos;
        }
    }

public:
    int expressiveWords(string S, vector<string>& words) {
        vector<int> pointers(words.size(),0);
        int sP = 0;
        int count=0;
        int sTotal = (int)S.size();
        char c = '*';
        while(sP < sTotal){
            std::cout<<"S[sP]:"<<S[sP]<<", c:"<<c<<std::endl;
            count = 1;
            c = S[sP];
            sP++;
            while(sP < sTotal){
                if(S[sP] == c){
                    count++;
                    sP++;
                }else{
                    break;
                }
            }
            _setWords(words, pointers, count,c);
        }
        int match=0;
        int i=0;
        for(auto &p:pointers){
            if(p != -1 && p == words[i].size()){
                match++;
            }
            i++;
        }
        return match;
    }
};
void test1(){
    Solution s;
    vector<string> words({"hello", "hi", "helo"});
    std::cout<<s.expressiveWords("helllllooo", words)<<std::endl;
}
void test2(){
    Solution s;
    vector<string> words({"aaaa"});
    std::cout<<s.expressiveWords("aaa", words)<<std::endl;
}
void test3(){
    Solution s;
    vector<string> words({"ggkyyfbbhdrxxsiixccqkmmiiivvvyyujccuuuhhwsnnttoyuuussggtttfeeebbbeedddqq","ggkyyfffbbhddrxxsiixccqqkmmmiiiivvvyyuujccuuuhhhwsnnttoyuuussggtttfebeedddddqq","ggkyyyyffbbhdrxxsiixccqkmmiiiivyyujccuhhwsssnnttoyuuussggtfebeeddddqq","ggkyyfffbbhdddrxxsiixccqkmmmiiiiivyyujccuuhhwsssnnttoyuuussggtfebbeeddddqq","ggkyyyyfffbbhdddrxxsiixccqkmmmiiivvvyyuujccuhhwssnnttoyuuussggtfeeebbbeedddddqq","ggkyyyyfffbbhddrxxsiixccqqkmiiiiivyyuuujccuuuhwsnnttoyuussggtfeebbbeedddddqq","ggkyyffbbhdddrxxsiixccqqkmiiiiivvyyuujccuhwsnnttoyussggtttfeeebbbeedddqq","ggkyyyfbbhddrxxsiixccqqqkmiiivvvyyuuujccuhhwsnnttoyuussggttfebeeddddqq","ggkyyyfbbhdrxxsiixccqqqkmmiiiivvyyujccuuhwsnnttoyussggtfeebbeedddqq","ggkyyyfbbhdddrxxsiixccqkmmmiiiivyyuujccuhhhwsssnnttoyuussggttfeeebeedddqq","ggkyyyfbbhdrxxsiixccqkmmiiiiivyyujccuhhhwssnnttoyussggtttfeebeedddqq","ggkyyyfffbbhddrxxsiixccqqqkmmmiiivvyyuuujccuuhhhwssnnttoyuussggttfeebeedddddqq","ggkyyfffbbhdrxxsiixccqqkmmiiiiivvyyuuujccuuuhhwsnnttoyuussggttfeebbeedddddqq","ggkyyfffbbhdddrxxsiixccqkmiiiivyyuuujccuuhwssnnttoyuussggtfebeedddddqq","ggkyyyyfffbbhddrxxsiixccqqkmmiiivyyuujccuuuhhwssnnttoyussggtfebbbeedddddqq","ggkyyyyffbbhdrxxsiixccqkmmiiiivyyujccuhwsssnnttoyussggtttfebeeddddqq","ggkyyyfbbhddrxxsiixccqqkmiiiiivvyyuuujccuhhhwsssnnttoyuuussggttfeeebbbeedddqq","ggkyyyyffbbhdddrxxsiixccqkmmmiiiivvvyyuuujccuuhhhwssnnttoyussggtttfeeebbbeeddddqq","ggkyyyfbbhdddrxxsiixccqqqkmiiivvvyyuujccuuhhwsnnttoyuuussggtfeebbbeedddqq","ggkyyyffbbhdddrxxsiixccqqqkmiiiivvyyuuujccuuhwssnnttoyuussggttfeebbbeedddqq","ggkyyyyfbbhdddrxxsiixccqkmmmiiiiivvvyyujccuuhhwsnnttoyuuussggttfebbbeedddddqq","ggkyyyfbbhdddrxxsiixccqqqkmmiiiivvyyuujccuuhhwssnnttoyuuussggttfebeeddddqq","ggkyyyyfbbhddrxxsiixccqkmmiiivvvyyuujccuuhhhwsnnttoyussggtfeeebbbeedddqq","ggkyyyfffbbhdrxxsiixccqqkmiiiiivvyyujccuuhwsnnttoyussggtttfeebbeedddddqq","ggkyyyyfffbbhddrxxsiixccqqqkmiiiivyyuuujccuuuhhwsssnnttoyuuussggttfebbeedddqq","ggkyyffbbhddrxxsiixccqkmiiivvyyujccuuhwssnnttoyuuussggtttfeebbeedddddqq","ggkyyyfffbbhdddrxxsiixccqqkmmmiiiiivvyyuuujccuuuhhwssnnttoyussggtttfeeebbeeddddqq","ggkyyyyfbbhddrxxsiixccqkmmmiiivvvyyujccuuhhhwssnnttoyuuussggtfeeebbeedddddqq","ggkyyyyfffbbhdddrxxsiixccqkmmmiiiivyyuuujccuhhhwsssnnttoyuussggtttfeeebbeedddddqq","ggkyyyyfbbhdrxxsiixccqqkmmiiiiivyyuujccuuuhhwsnnttoyuussggttfebbeedddqq","ggkyyyfbbhdrxxsiixccqkmiiiivvyyujccuhhhwsnnttoyussggttfeeebbeedddddqq","ggkyyyfffbbhddrxxsiixccqqqkmiiivyyuujccuuuhhwssnnttoyuuussggtfeebeedddqq","ggkyyffbbhdrxxsiixccqqkmmiiiiivyyuujccuhhhwsnnttoyuuussggtfebeedddddqq","ggkyyyfffbbhddrxxsiixccqkmiiiiivvvyyuujccuuuhhwsnnttoyuuussggttfeeebbeeddddqq","ggkyyyfffbbhdddrxxsiixccqqkmmmiiiivvyyuujccuuhwssnnttoyuussggtfebeedddqq","ggkyyfbbhdddrxxsiixccqqkmiiiiivyyujccuuuhhwsssnnttoyuuussggtttfeeebeeddddqq","ggkyyyyffbbhdddrxxsiixccqqkmmiiiiivvyyuuujccuuhhhwssnnttoyuussggtfeebbbeedddddqq","ggkyyffbbhdrxxsiixccqkmmiiiivyyuujccuuhhhwssnnttoyuussggtfeebeeddddqq","ggkyyyffbbhddrxxsiixccqkmmiiiiivvyyujccuuuhhwssnnttoyuussggtttfeeebbbeeddddqq","ggkyyyfffbbhdrxxsiixccqqqkmiiiivvvyyuujccuhhhwsssnnttoyuuussggtttfebbeeddddqq","ggkyyffbbhdrxxsiixccqqkmiiiiivyyuuujccuuuhwsnnttoyuuussggttfeeebbeeddddqq","ggkyyyfbbhdrxxsiixccqqkmiiivyyujccuuuhhhwsnnttoyussggtfebbbeeddddqq","ggkyyfffbbhddrxxsiixccqqkmmiiivyyuujccuuuhhwsnnttoyuussggtttfeeebbeedddddqq","ggkyyyyfbbhdrxxsiixccqqkmmmiiiiivvvyyujccuuuhhhwssnnttoyuussggtttfeebbeeddddqq","ggkyyyffbbhdrxxsiixccqqqkmiiiivvvyyuuujccuuhhhwsssnnttoyussggtttfeebeeddddqq","ggkyyyyfbbhddrxxsiixccqkmiiiiivvvyyuuujccuuuhhwssnnttoyuussggttfeeebeeddddqq","ggkyyyyffbbhdrxxsiixccqqkmmiiivvvyyuujccuuhhhwsnnttoyuussggttfeeebbbeedddqq","ggkyyfffbbhddrxxsiixccqkmiiiiivvyyuuujccuuuhwsssnnttoyuuussggtttfebeedddddqq","ggkyyyfbbhdrxxsiixccqkmmmiiiiivvyyuuujccuuuhwssnnttoyuussggttfeeebbeedddddqq","ggkyyyffbbhdrxxsiixccqkmmiiiivyyujccuuuhhwssnnttoyussggtttfebbbeeddddqq","ggkyyyffbbhdrxxsiixccqqkmmmiiiivvvyyuujccuhwssnnttoyussggtfebeeddddqq","ggkyyyffbbhdddrxxsiixccqqkmiiivvyyuujccuuhhhwssnnttoyussggtfeebbeeddddqq","ggkyyyffbbhdrxxsiixccqqqkmmiiiivvvyyujccuhhhwsnnttoyuuussggttfebbbeedddqq","ggkyyyfbbhddrxxsiixccqqkmiiiiivvyyuujccuuhhwsssnnttoyuuussggtfebbbeeddddqq","ggkyyffbbhddrxxsiixccqqkmmiiiiivvyyujccuhhhwsssnnttoyuuussggtttfeebbbeedddddqq","ggkyyyfffbbhdrxxsiixccqqkmiiivvyyuujccuhhwsssnnttoyuussggttfeeebbeedddqq","ggkyyyfffbbhdrxxsiixccqkmmmiiiivvyyuujccuuuhwssnnttoyussggtfebbbeeddddqq","ggkyyyyffbbhdrxxsiixccqqkmiiiivvvyyuuujccuuhwsnnttoyuussggttfebbbeedddddqq","ggkyyyyffbbhddrxxsiixccqqkmmmiiiiivvyyuuujccuhwsssnnttoyuussggtfeeebbeeddddqq","ggkyyyyfbbhdddrxxsiixccqqkmmiiivyyujccuuuhhwsssnnttoyussggtfebbeedddqq","ggkyyyffbbhdrxxsiixccqkmiiiiivvyyuujccuhhwssnnttoyussggtfebeedddqq","ggkyyyffbbhdrxxsiixccqkmmiiivyyujccuuhhhwsssnnttoyuuussggtttfeeebbbeeddddqq","ggkyyyyfffbbhdddrxxsiixccqqqkmmmiiiiivvyyujccuuhhhwssnnttoyuuussggtttfebbbeedddqq","ggkyyyfbbhdddrxxsiixccqqkmmiiivvvyyujccuuuhhhwssnnttoyuussggtttfebbbeeddddqq","ggkyyyfbbhdrxxsiixccqqqkmmmiiivvyyuuujccuuhhwsssnnttoyuuussggtttfebeedddqq","ggkyyyyfbbhddrxxsiixccqkmmiiiiivvvyyuuujccuuhhwssnnttoyuuussggtfeeebeedddddqq","ggkyyyyfffbbhdddrxxsiixccqqkmiiiivvyyujccuuhhwsssnnttoyussggtfebbbeedddqq","ggkyyyffbbhdrxxsiixccqqkmmmiiivvyyuuujccuhhhwsssnnttoyussggtttfebbbeeddddqq","ggkyyyfffbbhdddrxxsiixccqqkmmmiiiiivvvyyuuujccuuuhhwsnnttoyuussggttfeebeedddddqq","ggkyyyyfffbbhdddrxxsiixccqqqkmmmiiiivvyyuuujccuuuhhhwsssnnttoyussggtfeebbbeedddddqq","ggkyyyfbbhdddrxxsiixccqkmiiiiivyyuuujccuhhhwsnnttoyuussggtttfeebeedddqq","ggkyyyfbbhdrxxsiixccqqqkmmmiiiiivyyujccuhhwsnnttoyuussggttfeebbeedddqq","ggkyyyyffbbhdrxxsiixccqqqkmmiiivvyyujccuhhhwssnnttoyussggttfeeebbbeedddddqq","ggkyyyfffbbhdrxxsiixccqqqkmiiiiivyyujccuhhwsssnnttoyuuussggtfeebbbeeddddqq","ggkyyyffbbhdrxxsiixccqqkmiiiivvyyuuujccuhhhwssnnttoyussggttfeeebbbeedddqq","ggkyyyyffbbhdrxxsiixccqkmiiiiivvyyuujccuhhwssnnttoyuussggtfeeebeedddqq","ggkyyyfbbhdddrxxsiixccqkmmmiiivvyyujccuuhhhwsssnnttoyuussggtttfeebeedddddqq","ggkyyyyfffbbhdddrxxsiixccqqqkmmmiiiiivvvyyuuujccuuhwssnnttoyuuussggtfeeebbeedddddqq","ggkyyfbbhdrxxsiixccqkmiiiivvyyujccuuuhhhwssnnttoyuussggttfebbeedddqq","ggkyyyfbbhddrxxsiixccqqqkmmiiiivyyuujccuuhhwsnnttoyuussggttfebbeedddddqq","ggkyyyyfbbhdddrxxsiixccqkmmiiivyyujccuhwsssnnttoyussggttfeebbbeedddqq","ggkyyyyfbbhdrxxsiixccqkmiiiiivvvyyuuujccuuuhhwsnnttoyuuussggtfeebeeddddqq","ggkyyffbbhddrxxsiixccqqkmmiiiivyyuujccuuhhwsssnnttoyuussggtttfeeebbeedddqq","ggkyyyfffbbhddrxxsiixccqqqkmmiiivvvyyuujccuhhwsnnttoyuussggttfebbbeeddddqq","ggkyyfffbbhdrxxsiixccqkmmmiiivvvyyuuujccuuuhwsssnnttoyussggttfeeebeedddddqq","ggkyyyyffbbhdrxxsiixccqqqkmmiiiiivvyyuuujccuhhwsnnttoyuuussggtttfeeebbeedddqq","ggkyyyyfffbbhdrxxsiixccqkmmiiivvvyyuujccuhhwsssnnttoyuuussggttfeebbeedddddqq","ggkyyyyfffbbhdddrxxsiixccqqqkmiiivvyyuuujccuuhhhwssnnttoyuuussggttfebbbeedddddqq","ggkyyffbbhdrxxsiixccqqqkmmmiiiiivvvyyujccuuuhwsssnnttoyuussggtttfeeebbbeeddddqq","ggkyyyyfffbbhdddrxxsiixccqkmmmiiiiivyyujccuuuhwsnnttoyuuussggtttfeeebeedddddqq","ggkyyfffbbhdrxxsiixccqkmmmiiiiivvyyuujccuuuhwsssnnttoyussggtfebbeedddddqq","ggkyyyyfbbhddrxxsiixccqqqkmiiivyyuujccuuhhhwssnnttoyussggttfeeebbbeedddddqq","ggkyyffbbhddrxxsiixccqkmmiiivvvyyuuujccuuhhwsssnnttoyuuussggtfeeebbeedddddqq","ggkyyffbbhdddrxxsiixccqkmiiiivvvyyuujccuuhhhwsssnnttoyuuussggttfebbeedddqq","ggkyyyyffbbhdrxxsiixccqkmmmiiiiivyyuujccuuuhwsnnttoyuuussggtttfebeeddddqq","ggkyyffbbhddrxxsiixccqkmmmiiiivyyuuujccuuhhhwsssnnttoyuuussggtfeeebeedddqq","ggkyyyyfbbhdrxxsiixccqkmmmiiivyyuujccuhwsnnttoyuuussggtttfeeebbeeddddqq","ggkyyyyfffbbhdddrxxsiixccqqkmiiivvyyuujccuhhhwsnnttoyuuussggttfeeebbeedddqq","ggkyyyyfffbbhdddrxxsiixccqqkmmmiiivvyyuuujccuuuhwssnnttoyuussggtttfeebeedddqq","ggkyyyyfffbbhdddrxxsiixccqkmiiiiivyyuujccuuuhhwssnnttoyussggtttfeeebeeddddqq"});
    std::cout<<s.expressiveWords("ggkyyyyffffbbhddddrxxsiixccqqqqkmmmiiiiiivvvyyuuujccuuuhhhhwssssnnttoyuuuussggttttfeeeebbbbeedddddqq", words)<<std::endl;
}
#endif /* expressiveWords_hpp */
