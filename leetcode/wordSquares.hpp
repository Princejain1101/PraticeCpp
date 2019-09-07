//
//  wordSquares.hpp
//  leetcode
//
//  Created by Prince Jain on 6/17/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef wordSquares_hpp
#define wordSquares_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
//class Solution {
//    vector<vector<string>> _wordSquareUtil(vector<string>& words, vector<int> indices){
//        vector<vector<string>> result;
//        if(words[0].size() == indices.size()){
//            vector<string> ret;
//            for(auto &i:indices){
//                ret.push_back(words[i]);
//            }
//            result.push_back(ret);
//            return result;
//        }
//        for(int i=0; i<words.size(); i++){
////            if(indices.find(i) != indices.end()){
////                continue;
////            }
//            int j = (int)indices.size();
//            int found=1;
////            cout<<"j: "<<j<<endl;
//            for(int k=0; k<j;k++){
////                cout<<"checking k:"<<k<<", "<<words[indices[k]]<<": "<<words[i]<<endl;
//                if(words[i][k] != words[indices[k]][j]){
//                    found=0; //cout<<"not found"<<endl;
//                    break;
//                }
//            }
//            if(found){
//                indices.push_back(i);
//                vector<vector<string>> res = _wordSquareUtil(words, indices);
//                if(res.size()>0){
////                    cout<<"found result In for: "<<words[i]<<", size:"<<res.size()<<endl;
//                    for(auto &v:res){
//                        result.push_back(v);
//                    }
//                }
//                indices.pop_back();
//            }
//        }
//        return result;
//    }
//public:
//    vector<vector<string>> wordSquares(vector<string>& words) {
//        vector<vector<string>> result;
//        for(int i=0; i<words.size(); i++){
////            vector<string> square;
//            vector<int> indices;
//            indices.push_back(i);
////            square.push_back(words[i]);
//            vector<vector<string>> res = _wordSquareUtil(words, indices);
//            if(res.size()>0){
////                cout<<"found result for: "<<words[i]<<", size:"<<res.size()<<endl;
//                for(auto &v:res){
//                    result.push_back(v);
//                }
//            }
//        }
//        return result;
//    }
//};
class Solution {
    vector<vector<string>> _wordSquareUtil(vector<string>& words, unordered_map<int,int> indices){//, unordered_set<int> remainingIndices){
        vector<vector<string>> result;
        if(words[0].size() == indices.size()){
            vector<string> ret;
            for(int i=0; i<indices.size(); i++){
                int index = indices[i];
                ret.push_back(words[index]);
            }
            result.push_back(ret);
            return result;
        }
        int j = (int)indices.size();
        string sub = "";
        for(int k=0; k<j; k++){
            sub = sub + words[indices[k]][j];
        }
//        for(auto is=words.begin(); is!=words.end(); is++){
        for(int i=0; i<words.size(); i++){
//            int i= *is;
            string subc = words[i].substr(0,j);
            
            //            if(indices.find(i) != indices.end()){
            //                continue;
            //            }
//            int found=1;
////            cout<<"j: "<<j<<endl;
//            for(int k=0; k<j;k++){
////                cout<<"checking k:"<<k<<", "<<words[indices[k]]<<": "<<words[i]<<endl;
//                if(words[i][k] != words[indices[k]][j]){
//                    found=0; //cout<<"not found"<<endl;
//                    break;
//                }
//            }
            if(subc == sub){
                indices.insert(pair<int,int>(j,i));//push_back(i);
//                unordered_set<int> remInd = remainingIndices;
//                remInd.erase(remInd.find(i));
//                remainingIndices.erase(remainingIndices.find(i));
                vector<vector<string>> res = _wordSquareUtil(words, indices);//, remInd);
                if(res.size()>0){
//                    cout<<"found result In for: "<<words[i]<<", size:"<<res.size()<<endl;
                    for(auto &v:res){
                        result.push_back(v);
                    }
                }
                indices.erase(indices.find(j));
//                remainingIndices.insert(i);
//                indices.pop_back();
            }
        }
        return result;
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> result;
//        unordered_set<int> remainingIndices;
//        for(int i=0; i<words.size(); i++){
//            remainingIndices.insert(i);
//        }
        for(int i=0; i<words.size(); i++){
            //            vector<string> square;
            unordered_map<int,int> indices;
            indices.insert(pair<int,int>(0,i));
            //            square.push_back(words[i]);
            vector<vector<string>> res = _wordSquareUtil(words, indices);//, remainingIndices);
            if(res.size()>0){
                //                cout<<"found result for: "<<words[i]<<", size:"<<res.size()<<endl;
                for(auto &v:res){
                    result.push_back(v);
                }
            }
            indices.erase(indices.find(0));
        }
        return result;
    }
};

void test1(){
    Solution s;
    vector<string> words({"area","lead","wall","lady","ball"});
    vector<vector<string>> result = s.wordSquares(words);
//    cout<<"result"<<endl;
    for(auto &vec: result){
        for(auto &s:vec){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void test2(){
    Solution s;
    vector<string> words({"abat","baba","atan","atal"});
    vector<vector<string>> result = s.wordSquares(words);
    //    cout<<"result"<<endl;
    for(auto &vec: result){
        for(auto &s:vec){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void test3(){
    Solution s;
    vector<string> words({"baffs","sloop","octad","brens","gammy","sones","perdy","myope","burbs","doeth","yirds","bolls","veils","pause","niton","kibbi","salal","redid","gaped","anise","derby","oinks","dormy","wagon","soupy","ephah","goody","foals","rusks","memos","pareo","levee","prosy","earls","gator","urged","welly","boils","wells","gecko","cline","gamps","shaft","jiver","eyers","packs","eased","adman","ackee","recce","defog","cadis","jives","germy","umbos","gypsy","miler","swive","clubs","plots","fille","dodos","sylph","indol","lodes","chore","flute","tauts","chams","poilu","folds","jimpy","yodhs","swang","thymi","spite","equal","wrack","roses","degas","etyma","yecch","phyle","ducks","scape","tepas","flams","nidal","sells","geest","talus","bilgy","weets","dorps","wolfs","bilks","spurn","rinse","serfs","iodid","hying","boast","leben","fussy","stour","eches","bored","cones","tiled","forms","purda","pants","whops","udder","coles","apeak","nippy","skimp","jolty","ilium","ordos","shews","title","grate","kibes","pryer","bleep","utile","orles","lamia","selva","meant","frump","gaurs","defat","ormer","cramp","cured","sloyd","bates","bowed","samek","knave","jupon","exons","plica","uncus","murrs","sowed","fishy","halid","nisus","fives","spays","quoth","rants","justs","sewed","orzos","click","kings","repay","grope","bring","teach","expos","supra","dight","lines","shred","chide","biked","fugue","manna","bruin","mouch","syces","sophs","retax","alary","litai","unrig","dwell","jells","thuja","ovals","snare","snide","abate","femme","numbs","fount","undid","pyxes","warms","fines","ansae","fards","nabis","garni","false","naric","hales","tores","kilty","rewon","grail","synth","vowel","sagas","progs","snags","genii","swath","pross","exine","jaups","desex","acmes","pilei","treed","genic","weeks","hosed","chela","suave","duple","anger","cohos","dahls","essay","grans","tarty","vines","shoal","north","hertz","pecks","fairs","hylas","ochry","parge","witan","shawm","nylon","plier","kolas","umiaq","zoeal","apple","abaca","miked","meths","karma","yummy","thorn","tuyer","nappe","duels","shame","rowdy","plush","toyos","batts","emirs","braxy","quilt","voles","ileus","husks","kinos","vying","segue","toker","wynds","scaly","tardy","preed","wonts","prune","ikons","asset","evoke","rosin","omasa","fados","jehad","vises","roues","laris","snack","bhuts","edify","cloys","newts","sonic","teams","kempt","peeve","biffs","cisco","begot","knout","pesos","soldi","appal","unwon","axles","shins","decay","betta","hence","gowan","froes","usury","early","sugar","sotol","boggy","roads","exult","cheap","shivs","stiff","whigs","ousel","livre","flush","jaunt","clued","venue","green","promo","gybes","vimen","amici","dumky","kalpa","oboli","chafe","parch","shrub","raped","magus","cozey","braze","ikats","skats","jupes","irate","gibed","pecky","evict","synod","plums","puffs","drupe","rumor","scrip","sappy","yells","shiel","beaux","apses","damps","lamed","gally","wines","skids","laked","blimp","spoil","beech","plage","mothy","bally","gager","flora","latke","secco","salve","peony","overt","tofus","yogic","finer","kinin","rakis","tunas","lolly","trash","boart","fordo","longs","lacer","momus","moory","picul","ament","cocci","taper","luged","scuff","azure","gaffe","tubby","opsin","twits","veldt","forgo","lotah","banes","murid","venin","sooty","bhang","allow","scour","lours","chubs","ureal","basts","argot","rehem","ichor","kerne","shear","copse","bathe","perky","onion","stade","bises","dopes","dexie","peens","letch","gamer","passe","sudds","prahu","yerks","hippy","oxeye","rills","gulpy","dulse","hokey","tammy","paler","cutin","kafir","tarps","zowie","eruct","upbow","armed","viced","rosed","strap","shuls","harps","whizz","epics","manos","elver","kefir","noter","bowls","kicks","pewee","fugus","hiker","vexil","tides","manes","crepy","relay","acres","snobs","kecks","vogie","dowel","theft","doozy","daffy","joked","pecan","zineb","chias","grain","point","spate","shalt","rayed","kolos","jurat","mooed","grows","scuba","skees","exams","tutti","aliya","wiles","pilot","netty","nabes","berme","poind","zones","coyed","abaci","panty","moved","peise","sughs","llano","volte","peppy","shies","mixed","whale","whity","bandy","layup","nodus","vigas","fifes","oared","daddy","waspy","dales","crony","pikes","reifs","kaiak","coted","hyper","monks","bravi","diner","slung","rishi","bawdy","steps","cusks","wiver","trips","slink","ambit","genie","dikes","faker","quags","savin","amids","desks","spook","gonof","whisk","hotel","brags","carny","queer","poler","pawns","toner","nowts","truce","pekes","reeds","baals","ouzel","dairy","hoers","sepal","butle","petit","mucky","liege","rajah","cades","bogie","esses","juicy","kelly","bogus","silly","dotes","direr","tucks","aglee","miffy","freak","dildo","maids","words","cakes","ocker","lurid","tophs","event","drams","leash","clags","plank","butts","ruffe","sends","actor","dials","mesas","caput","yearn","suite","yucca","naevi","swots","namer","sojas","along","crams","eyrie","brins","comer","blocs","spade","hexad","steel","moony","nyala","lathe","grego","titty","gleys","melic","aunty","sural","shool","avers","rides","getup","barbe","bluey","saute","globs","foods","amiga","triol","qaids","deign","leone","gawks","heigh","dexes","shits","lodge","dives","obits","ileum","whets","power","duked","helix","yogas","skeps","sluff","bleak","chess","spend","force","haver","snubs","punts","reuse","debye","cubit","buret","pepla","ziram","route","pined","still","spica","alifs","gazoo","balsa","papal","twier","didos","carns","gulls","bakes","brows","gulch","cadgy","jakes","ethic","tuffs","alley","ossia","faery","glial","tawny","carpi","smaze","champ","gated","quest","dines","middy","guilt","vitta","sicko","kaury","yills","soled","flics","tache","avgas","sages","belay","arils","erect","omits","mopes","weedy","spode","glove","stack","omens","years","roven","tythe","zloty","chirr","keeps","ridgy","mover","range","sutta","eight","misdo","issue","bebop","juked","turbo","tough","emits","prude","hogan","infer","quash","reefy","toros","annul","muser","turds","flans","clomp","fails","equip","oasis","covey","iodic","tense","chimp","whaup","lores","spake","sasin","those","lough","lacey","skegs","heist","loved","times","sulks","beige","potto","zerks","dryer","towed","dined","cerci","flung","fluke","elemi","schmo","phons","dropt","bales","argle","carom","whort","gloze","hymns","twirl","amiss","atmas","cates","pukes","craps","sirup","balks","domes","retag","dorky","septa","spiks","shads","gemma","beets","inlet","ropes","aroma","chits","thuds","peels","fogie","stela","mythy","drier","thrip","burst","salad","rainy","bilge","woful","prick","props","stock","ofays","hosel","areic","clang","sexes","pyxie","haled","nawab","boche","fanos","aurum","tours","funky","dynes","raias","hexyl","welch","shyly","hemic","shade","netts","fiefs","topis","muton","nicol","updos","jubes","blite","xebec","swear","moult","pagod","cecum","rewet","nopal","holds","ruana","meany","juice","cobbs","mated","helms","dared","muley","bails","tench","blimy","tepoy","duroc","helps","quasi","stake","galas","mizen","spics","scudi","stook","pleas","hooly","gowks","hocks","hooey","octan","modal","minny","gaudy","neats","calfs","troop","amaze","zebra","jemmy","berms","shent","spasm","batty","menad","porks","jests","miaou","busty","buran","endow","juror","arias","stall","carry","tarre","colog","grout","ixias","alecs","resee","jowly","lochs","nines","yangs","byssi","sixty","gyros","tools","every","penes","dinks","storm","arles","chiro","waler","masts","gluts","siver","antre","treat","flair","lurks","overs","ratal","audit","tipis","vroom","spank","moors","paves","vinos","ghost","opine","toras","cauld","mokes","antsy","liman","outer","mufti","gores","baled","urine","minds","sorbs","hefty","cozen","musky","booed","wrier","jibes","reify","block","rebus","atoms","risus","zetas","dauby","rayas","razee","sagos","roset","yarer","fetes","award","filth","credo","gutsy","inter","yards","obeah","waist","oyers"});
    vector<vector<string>> result = s.wordSquares(words);
    //    cout<<"result"<<endl;
    for(auto &vec: result){
        for(auto &s:vec){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

#endif /* wordSquares_hpp */
