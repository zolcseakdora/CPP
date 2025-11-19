#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
using namespace std;

int main() {
    Student student1(1,"Zolcseak","Dora");
    student1.addGrade("roman",7.70);
    student1.addGrade("magyar",8.80);
    student1.addGrade("matek",9.45);
    student1.addGrade("info",8.60);
    student1.computeAverage();
    cout<<"atlag"<<student1<<endl;

    GraduationDao dao(2023);
    dao.enrollStudents("./nevek.txt");
    dao.readGradesSubject("Math", "./math.txt");
    dao.computeAverage();

    cout << "Enrolled: " << dao.numEnrolled() << endl;
    cout << "Passed: " << dao.numPassed() << endl;

    return 0;
}