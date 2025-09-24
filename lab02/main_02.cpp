#include <iostream>
#include "Point.h"
using namespace std;
int main(int argc, char** argv) {
 Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
 Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;

 Point * pp1 = new Point(300, 400);
 Point * pp2 = new Point(500, 1000);

    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;

cout << "Distance between p1 and p2: " << distance(p1, p2) << endl;

Point a(0, 0), b(0, 1), c(1, 1), d(1, 0);
    cout << "Square? " << (isSquare(a, b, c, d) ? "Yes" : "No") << endl;

testIsSquare("points.txt");

srand(time(0));
int n=10;
Point *points=createArray(n);
/*
for(int i=0; i<n; ++i){
    points[i].print();
    cout<<endl;
}
*/
printArray(points,n);
 delete points;
 delete pp1;
 delete pp2;
 return 0;
}