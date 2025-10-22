#include "User.h"
int User::nextId=1;
User ::User( const string& userName )
  :id(nextId++),userName(name){}

int getId() const{
    return id;

}
string getName() const{
    return name;
}

void addResult(int quizId, double scorePercent){
    results.insert({quizId,scorePercent});
}

void showResults() const{
  cout<<name<<" ";
  for( const auto&[quizId,scorePercent]:results){
    cout<<quizId<<":"<<scorePercent<<endl;
  }
}

friend ostream& operator<<(ostream& os, const User& user){
  os << "Felhasználó " << user.id << "  " << user.name;
    return os;
}