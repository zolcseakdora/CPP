#include "QuizItem.h"
#include "Quiz.h"
#include "User.h"
#include "QuizGame.h"
#include <iostream>
using namespace std;

int main() {
    // 1️⃣ Kvíz létrehozása
    Quiz quiz("Történelem Kvíz");
    vector<string> answers1 = {"1914", "1939", "1945"};
    QuizItem q1("Mikor kezdődött a II. világháború?", answers1, 1);
    
    vector<string> answers2 = {"Oroszország", "Németország", "Franciaország"};
    QuizItem q2("Melyik ország támadta meg Lengyelországot 1939-ben?", answers2, 1);

    quiz.addItem(q1);
    quiz.addItem(q2);
    quiz.finalize();

    // 2️⃣ Felhasználó
    User user("Kiss Péter");

    // 3️⃣ Játék
    QuizGame game(user, quiz);
    game.play();

    // 4️⃣ Eredmények megtekintése
    user.showResults();

    return 0;
}
