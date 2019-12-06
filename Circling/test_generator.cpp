#include <vector>
#include <math.h>
#include <iostream>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Help_func.cpp>

using namespace std;


class Test_Generator{
    public:
    point cent_point;
    point luc; // Left upper corner
    point rdc; // Right down corner
    circle target_circle;
    double distortion;
    
    Test_Generator(){
        distortion = 0;
    }
    Test_Generator(circle c, point _luc, point _rdc){
        target_circle = c.copy();
        luc = _luc.copy();
        rdc = _rdc.copy();
        distortion = 0;
    }
    Test_Generator(circle c, point _luc, point _rdc, double _distortion){
        target_circle = c.copy();
        luc = _luc.copy();
        rdc = _rdc.copy();
        distortion = _distortion;
    }
    point_matrix simple_generate(){
        pms points;
        for(int x = luc.x; x <= rdc.x; x++){
            for(int y = luc.y; y <= rdc.y; y++){
                point this_point = point(x, y);
                if (dist(cent_point, this_point) <= target_circle.r){
                    points.push_back(this_point);
                }
            }
        }
        return point_matrix(points);
    }
};