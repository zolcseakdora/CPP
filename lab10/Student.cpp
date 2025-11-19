#include "Student.h"
#include <iostream>

void Student::setId(int id) {
    this->id = id;
}

void Student::addGrade(const string& subject, double grade){
    grades[subject]=grade;
}

void Student:: computeAverage(){

    if(grades.empty()){
        average=0.0;
        return;
    }
    double sum=0.0;
    bool atment=true;
    for(auto & a:grades){
        sum+=a.second;
        if(a.second<5.00) atment=false;
    }
    if(!atment || sum/grades.size()<6.00){
        average=0.0;
    }
    else{  
        average=sum/grades.size();
    }

}

ostream &operator<<(ostream &os, const Student &student) {
    os << "ID: " << student.id << ", "
       << "Name: " << student.firstName << " " << student.lastName << ", "
       << "Average: " << student.average;
    return os;
}