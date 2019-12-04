#include <iostream>
#include <vector>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Circling\Circle finder.cpp>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Help_func.cpp>

using namespace std;


int main(){
    pms points;
    point point1 {1, 1};
    point point2 {1, 3};
    point point3 {-1, 3};

    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);

    point_matrix p = point_matrix(points);

    p.print();

    return 0;
}