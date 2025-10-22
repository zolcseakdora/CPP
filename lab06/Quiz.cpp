#include "Quiz.h"

Quiz :: Quiz(int quizId,const string& quizName )
  :id(quizId),name(quizName),isReady(false){}

void addItem(const QuizItem& item){
    if(!isReady){
        items.push_back(item);
    }
}

void finalize(){
    isReady=true;
}

int getId() const{
    return id;
 }
std::string getName() const{
    return name;
}
bool getIsReady() const{
    return isReady;
}
vector<QuizItem> getItems() const{
    return items;
}