#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include "QuizItem.h"
using namespace std;
class Quiz {
private:
    static int nextId;       
    int id;
    string name;
    vector<QuizItem> items;
    bool isReady;

public:
    Quiz(conststring& quizName);

    void addItem(const QuizItem& item);
    void finalize();

    int getId() const;
    string getName() const;
    bool getIsReady() const;
    vector<QuizItem> getItems() const;
};

#endif
