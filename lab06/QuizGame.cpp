#include "QuizGame.h"
using namespace std;
QuizGame::QuizGame(User& userR, Quiz& quizR)
  :user(userR), quiz(quizR){}

void play(){
    if (!quiz.getIsReady()) {
        cout << "A kvíz nincs lezárva, nem futtatható!\n";
        return;
    }

int correctCount = 0;
int totalQuestions = items.size(); 

for (const auto& item : items) {
    cout << item << "\n";
    int answer;
    cout << "Válaszod (szám): ";
    cin >> answer;

    if (item.checkAnswer(answer)) {
        cout << "Helyes!\n";
        correctCount++;
    } else {
        cout << "Rossz válasz!\n";
    }
    cout << "--------------------------\n";
}

cout << "Helyes válaszok: " << (double)correctCount/totalQuestions << "\n";

}
