#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class QuizItem {
private:
    static int nextId;
    int id;
    string question;
    vector<std::string> answers;
    int correctAnswer;

public:
    QuizItem(const string &quisteonText, const string &possibleAnswer, int correctIndex )
    int getId() const;
    string getQuestion() const;
    vector<std::string> getAnswers() const;
    int getCorrectAnswerIndex() const;
    bool checkAnswer(int userChoice) const;
};
#endif
