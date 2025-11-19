#include <iostream>
#include <fstream>
#include <sstream>
#include "GraduationDao.h"
using namespace std;

void GraduationDao::enrollStudents(const string &filename){
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file");
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idg, firstNameg, lastNameg;

        ss >> idg >> firstNameg >> lastNameg;

        int id = stoi(idg);

        students.emplace(id, Student(id, firstNameg, lastNameg));
    
    }

}
void GraduationDao:: readGradesSubject(const string &subject, const string &filename){
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file");
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string ids,gradess;
        ss>>ids>>gradess;

        int id = stoi(ids);
        double grade = stod(gradess);

        auto it = students.find(id);
        if (it != students.end()) {
            it->second.addGrade(subject, grade);
        }
    }
}

void GraduationDao:: computeAverage(){
    for (auto &av : students) {
        av.second.computeAverage();
    }
}
int GraduationDao::numEnrolled() const{
    return students.size();
}

int GraduationDao::numPassed() const{
    int cnt=0;
    for( const auto& a: students){
        const Student &st = a.second;
        if(st.getAverage() > 6.00){
            ++cnt;
        }
    }
    return cnt;
}
Student GraduationDao::findById(int id) const{
    return students.at(id);

}
double GraduationDao::getAverageBySubject(const string &subject) const{
    double sum = 0.0;
    int count = 0;

    for (const auto &s : students) {
        const Student &st = s.second;
        try {
            double grade = st.getGrade(subject);
            sum += grade;
            count++;
        } catch (const out_of_range &) {
        }
    }
    if (count == 0) {
        throw out_of_range("Nincs jegye");
    }
    return sum / count;

}