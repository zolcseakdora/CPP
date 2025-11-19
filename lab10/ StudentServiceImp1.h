#ifndef STUDENTSERVICE1_H
#define STUDENTSERVICE1_H
#include <iostream>
#include "GraduationDao.h"
using namespace std;
class StudentServiceImp1 : public StudentService{
    GraduationDao *dao;
public:
    StudentServiceImp1(GraduationDao *dao) : dao(dao) {}
    virtual bool isEnrolled(int id) const override;
    virtual vector<string> getSubjects(int id) const override;
    virtual double getResultBySubject(int id, const string& subject) const override;
    virtual double getAverage(int id) const override;
    virtual bool isPassed(int id) const override;
};
#endif