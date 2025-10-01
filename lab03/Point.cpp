#include "Point.h"
#include <iostream>
#include <cmath>
#include <set>
#include <fstream>
#include <cstdlib>
using namespace std;
Point::Point(int x, int y) {
 if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
 }
 else {
        this->x = 0;
        this->y = 0;
 }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}
void Point::print() const {
    cout << "(" << x << ", " << y << ")";
}
double distance(const Point& a, const Point& b){
    // t=gyok (x.a-x.b)^2 +(y.a-y.b)^2
    return sqrt((a.getX()-b.getX())^2+(a.getY()-b.getY())^2);
}
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d){
    set<double> distances;
    distances.insert(distance(a, b));
    distances.insert(distance(a, c));
    distances.insert(distance(a, d));
    distances.insert(distance(b, c));
    distances.insert(distance(b, d));
    distances.insert(distance(c, d));
    
    return distances.size()==2;

}
void testIsSquare(const char * filename){
    ifstream file("points.txt");
    if(!file) {
        cout<<"file megnyitasi hiba"<<endl;
        exit(1);
    }
    int a,b,c,d,e,f,g,h;
    file>>a>>b>>c>>d>>e>>f>>g>>h;
    Point p1(a,b);
    Point p2(c,d);
    Point p3(e,f);
    Point p4(g,h);

    if (isSquare(p1, p2, p3, p4)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    file.close();
}
Point* createArray(int numPoints){
    Point *points= new Point[numPoints];
    for(int i=0; i<numPoints; ++i){
        int x=rand()%2001;
        int y=rand()%2001;
        points[i]=Point(x,y);
    }
    return points;
}
void printArray(Point* points, int numPoints){
    for(int i=0; i<numPoints;++i){
        points[i].print();
        cout<<endl;
    }
}