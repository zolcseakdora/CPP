#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName): id(id), firstName(firstName), lastName(lastName){ };
    int getId() const{
        return id;
    }
    void setId(int id);
    const string &getFirstName()const{
        return firstName;
    }
    const string &getLastName() const{
        return lastName;
    }
    void addGrade(const string& subject, double grade);
    double getGrade(const string& subject) const {return grades.at(subject);}//throws out_of_range for nonexistent subject
    const map<string, double> &getGrades() const{
        return grades;
    }
    void computeAverage();
    double getAverage() const{
        return average;
    }
    friend ostream& operator<<(ostream& os, const Student& student);
};
#endif