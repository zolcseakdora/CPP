#ifndef GRADUATIONDAO_H
#define GRADUATIONDAO_H

#include <string>
#include <map>
#include "Student.h"

using namespace std;
class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void readGradesSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
    Student findById(int id) const; //throws out_of_range exception for nonexistent id
    double getAverageBySubject(const string &subject) const;
};

#endif