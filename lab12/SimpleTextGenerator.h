
#ifndef SIMPLETEXTGENERATOR_H
#define SIMPLETEXTGENERATOR_H

#include <map>
#include <string>
#include <vector>
#include "TextGenerator.h"
using namespace std;

class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    //virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    //void printData() const; // a map kiíratása
};

#endif // SIMPLETEXTGENERATOR_H
