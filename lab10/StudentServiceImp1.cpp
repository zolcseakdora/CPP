#include <iostream>
#include "StudentServiceImp1.h"
using namespace std;
virtual bool isEnrolled(int id) const override { 
    try { dao->findById(id); // kivételt dob, ha nincs return true; 
     } 
    catch (const out_of_range&) {
         return false; 
        }
    }