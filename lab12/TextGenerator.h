#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include <string>
#include <iostream>
using namespace std; 

class TextGenerator {
public:
    virtual void trainFromText(std::string trainingText) = 0;
    // virtual void trainFromFile(std::string filename) = 0;
    virtual std::string generate(std::string startWords, int numWords = 10) = 0;

    // virtual ~TextGenerator() = default;
};

#endif // TEXTGENERATOR_H
