#ifndef QUIZGAME_H
#define QUIZGAME_H

#include "User.h"
#include "Quiz.h"
#include <iostream>
using namespace std;

class QuizGame {
private:
    User& user;   
    Quiz& quiz;   

public:
    QuizGame(User& user, Quiz& quiz);

    void play();  
};

#endif
