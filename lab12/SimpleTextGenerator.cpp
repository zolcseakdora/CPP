#include "SimpleTextGenerator.h"
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string cleanWord(const string &word){
    string res="";
    for(int i=0; i<word.length(); ++i){
        char c= word[i];
        if(c>='A' && c<='Z'){
            c+=tolower(c);
        }
        if(isalpha(c)){
             res+=c;
        }
    }
    return res;
}

void SimpleTextGenerator::trainFromText(string trainingText){
    vector<string>words;
    stringstream ss(trainingText);
    string word;
    while(ss>>word){
        words.push_back(cleanWord(word));
    }
    /*for(auto &word : words){
        cout<<word<< endl;
    }*/
   for(int i=0; i<words.size()-1;++i){
    string key= words[i]+" "+words[i+1];
    if(i+2<words.size()){
        data[key].push_back(words[i+2]);
    }
    else{
        data.insert({key,vector<string>()});
    }
   }
   for(auto &pair: data){
        cout<<pair.first<<": ";
        for(auto pairValue: pair.second){
            cout<<pairValue<<" ";
        }
    }
}


string SimpleTextGenerator::generate(string startWords, int numWords){
    string ss(startWords+" ");
    srand(time(NULL));
    // sleep(5);
    for(int i=0; i<numWords;++i){
        auto it = data.find(startWords);
        if(it==data.end()){
            return ss;
        }
        auto size=it->second.size();
        if(size==0){
            return ss;
        }
        int pos =rand()%size;
        ss += it->second[pos] + " ";
        stringstream twoWords(startWords);
        string word2;
        twoWords>>word2>>word2;
        startWords=word2+" "+it->second[pos];
    }
    return ss;
}