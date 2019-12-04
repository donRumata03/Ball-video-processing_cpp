#include <vector>
#include <math.h>
#include <iostream>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Help_func.cpp>

using namespace std;



double error_function(pms &points, double r, point center){
    pms edges = detect_edges(points);
    double err = 0;
    for(int i = 0; i < edges.size(); i++){
        point this_point {edges.at(i).x, edges.at(i).y};
        err += pow(dist(center, this_point), POINT_DIST_POW);
    }
    return err;
}


pms detect_edges(pms &points){
    return points;
}