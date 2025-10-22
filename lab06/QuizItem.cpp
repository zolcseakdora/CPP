#include "QuizItem.h"
int QuizItem :: nextId=1;

QuizItem :: QuizItem(const string& questionText, 
                    const vector<string>&possibleAnswer,
                    int correctIndex)
        :question(questionText),answers(possibleAnswer),correctAnswer(correctIndex)
{
    id=nextId++;
}
int getId() const{
    return id;
}
string getQuestion() const{
    return question;
}
vector<std::string> getAnswers() const{
    return answers;
}
int getCorrectAnswerIndex() const{
    return correctAnswer;
}
bool QuizItem::checkAnswer(int userChoice) const {
    return (userChoice - 1) == correctAnswer;
}
