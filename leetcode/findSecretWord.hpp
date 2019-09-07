//
//  findSecretWord.hpp
//  leetcode
//
//  Created by Prince Jain on 6/22/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findSecretWord_hpp
#define findSecretWord_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <time.h>

using namespace std;
class Master {
    string secret;
    vector<string> wordlist;
    map<string,int> wordcost;
    bool found=false;
    int calls=0;
    int _getMatchCost(string w1, string w2){
        int cost=0;
        for(int i=0; i< w1.size(); i++){
            if(w1[i]==w2[i])
                cost++;
        }
        return cost;
    }
    public:
    int guess(string word){
        calls++;
        if(wordcost.find(word) != wordcost.end()){
            if(word==secret) found = true;
            return wordcost[word];
        }
        return -1;
    }
    void setSecret(string word){secret = word;}
    void setWordList(vector<string> words){
        wordlist = words;
    }
    void setWordCost(){
        for(auto &w:wordlist){
            wordcost.insert(pair<string,int>(w,_getMatchCost(w, secret)));
        }
    }
    bool getFound(){return found;}
    int getCalls(){return calls;}
};
//map<string,int> Master::wordcost({
//    pair<string,int>("acckzz",6),
//    pair<string,int>("ccbazz",3),
//    pair<string,int>("eiowzz",2),
//    pair<string,int>("abcczz",4)
//});
class Solution {
    int _getMatchCost(string w1, string w2){
        int cost=0;
        for(int i=0; i< w1.size(); i++){
            if(w1[i]==w2[i])
                cost++;
        }
        return cost;
    }
    vector<string> _getWordsWithCost(vector<string>& wordlist, string word, int cost){
        vector<string> newwordlist;
        for(auto &w:wordlist){
            if(_getMatchCost(w, word)==cost) {
                newwordlist.push_back(w);
            }
        }
        return newwordlist;
    }
public:
    bool _findSecretWordUtil(vector<string>& wordlist, Master& master, int prevmatch) {
        srand(time(NULL));
        int wsize = (int)wordlist.size();
        if(wsize<=0)
            return false;
        set<int> previ;
        int index = rand()%wsize;
        for(int i=0; i<wsize; i++){
            while(previ.find(index)!=previ.end()){
                index = rand()%wsize;
            }
            previ.insert(index);
//            cout<<"index: "<<index<<", wsize: "<<wsize<<endl;
            int match = master.guess(wordlist[index]);
//            cout<<"word: "<<wordlist[index]<<": "<<match<<endl;
            if(match==6){
                return true;
            }
//            if(match <= prevmatch)
//                continue;
            vector<string> newwordlist = _getWordsWithCost(wordlist, wordlist[index], match);
            if(_findSecretWordUtil(newwordlist, master, match))
               return true;
        }
        return false;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        _findSecretWordUtil(wordlist, master, 0);
    }
};
void test1(){
    Solution s;
    vector<string> wordlist({"acckzz","ccbazz","eiowzz","abcczz"});
    Master master;
    master.setSecret("acckzz");
    master.setWordList(wordlist);
    master.setWordCost();
    s.findSecretWord(wordlist, master);
    cout<<"calls: "<<master.getCalls()<<", found: "<<master.getFound()<<endl;
}
void test2(){
    Solution s;
    vector<string> wordlist({"gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw","ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz","zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb","tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc","tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve","rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn","coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls","tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe","rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp","jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz","hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn","blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj","ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk"});
    Master master;
    master.setSecret("hbaczn");
    master.setWordList(wordlist);
    master.setWordCost();
    s.findSecretWord(wordlist, master);
    cout<<"calls: "<<master.getCalls()<<", found: "<<master.getFound()<<endl;
}
void test3(){
    Solution s;
    vector<string> wordlist({"eykdft","gjeixr","eksbjm","mxqhpk","tjplhf","ejgdra","npkysm","jsrsid","cymplm","vegdgt","jnhdvb","jdhlzb","sgrghh","jvydne","laxvnm","xbcliw","emnfcw","pyzdnq","vzqbuk","gznrnn","robxqx","oadnrt","kzwyuf","ahlfab","zawvdf","edhumz","gkgiml","wqqtla","csamxn","bisxbn","zwxbql","euzpol","mckltw","bbnpsg","ynqeqw","uwvqcg","hegrnc","rrqhbp","tpfmlh","wfgfbe","tpvftd","phspjr","apbhwb","yjihwh","zgspss","pesnwj","dchpxq","axduwd","ropxqf","gahkbq","yxudiu","dsvwry","ecfkxn","hmgflc","fdaowp","hrixpl","czkgyp","mmqfao","qkkqnz","lkzaxu","cngmyn","nmckcy","alpcyy","plcmts","proitu","tpzbok","vixjqn","suwhab","dqqkxg","ynatlx","wmbjxe","hynjdf","xtcavp","avjjjj","fmclkd","ngxcal","neyvpq","cwcdhi","cfanhh","ruvdsa","pvzfyx","hmdmtx","pepbsy","tgpnql","zhuqlj","tdrsfx","xxxyle","zqwazc","hsukcb","aqtdvn","zxbxps","wziidg","tsuxvr","florrj","rpuorf","jzckev","qecnsc","rrjdyh","zjtdaw","dknezk"});
    Master master;
    master.setSecret("cymplm");
    master.setWordList(wordlist);
    master.setWordCost();
    s.findSecretWord(wordlist, master);
    cout<<"calls: "<<master.getCalls()<<", found: "<<master.getFound()<<endl;
}

#endif /* findSecretWord_hpp */
