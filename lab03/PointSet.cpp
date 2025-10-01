#include "PointSet.h"
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>

PointSet::PointSet(int n):n(n){
    srand(time(0));
    for(int i=0; i<n; ++i){
        double x=rand()%101;
        double y=rand()%101;
        points.push_back(Point(x,y));
    }
    computeDistances();
}

void PointSet::computeDistances(){
   for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = points[i].getX() - points[j].getX();
            double dy = points[i].getY() - points[j].getY();
            double d = sqrt(dx * dx + dy * dy);
            distances.push_back(d);
        }
    }
}

double PointSet::maxDistance() const
{
    return *max_element(distances.begin(),distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (const auto& p : points) {
        p.print();
    }
}

void PointSet::printDistances() const{
     for (double d : distances) {
        cout << d << " ";
    }
    cout << std::endl;
}

void PointSet::sortPointsX(){
    sort(points.begin(),points.end(),[](const Point& a, const Point& b){
        return a.getX()<b.getX();
    });
}

void PointSet::sortPointsY(){
    sort(points.begin(),points.end(),[](const Point& a, const Point& b){
        return a.getY()<b.getY();
    });
}

void PointSet::sortDistances(){
    sort(distances.begin(),distances.end());
}

int PointSet::numDistinctDistances(){
    set<double> numDistinctDistances(distances.begin(), distances.end());
    return numDistinctDistances.size();
}
