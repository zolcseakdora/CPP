#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include <iostream>
using namespace std;
class User {
private:
    static int nextId;                 
    int id;                            
    string name;                  
    map<int, double> results;     

public:
    User(const string& name);

    int getId() const;
    string getName() const;

    void addResult(int quizId, double scorePercent);
    void showResults() const;

    friend ostream& operator<<(ostream& os, const User& user);
};

#endif
