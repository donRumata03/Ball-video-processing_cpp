#include <vector>
#include <math.h>
#include <iostream>
#include <D:/Projects/Video_anal/Help_func.cpp>

using namespace std;


class Test_Generator{
    public:
    point cent_point;
    point luc; // Left upper corner
    point rdc; // Right down corner
    circle target_circle, distort_circle;
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
    Test_Generator(circle c, point _luc, point _rdc, circle _distort_circle, double _distortion){
        target_circle = c.copy();
        distort_circle = _distort_circle.copy();
        luc = _luc.copy();
        rdc = _rdc.copy();
        distortion = _distortion;
    }
    Test_Generator(circle c, point _luc, point _rdc, circle _distort_circle){
        target_circle = c.copy();
        distort_circle = _distort_circle.copy();
        luc = _luc.copy();
        rdc = _rdc.copy();
        distortion = 0;
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

    point_matrix generate_moon_distortion(){
        pms points;
        for(int x = luc.x; x <= rdc.x; x++){
            for(int y = luc.y; y <= rdc.y; y++){
                point this_point = point(x, y);
                if (target_circle.in(this_point) && (!distort_circle.in(this_point))){
                    points.push_back(this_point);
                }
            }
        }
        return point_matrix(points);
    }
    point_matrix generate_random_distortion(){
        pms points;
        for(int x = luc.x; x <= rdc.x; x++){
            for(int y = luc.y; y <= rdc.y; y++){
                point this_point = point(x, y);
                if (target_circle.in(this_point) && (!distort_circle.in(this_point))){
                    if ((dist(this_point, target_circle.center) == target_circle.r) && (dist(this_point, distort_circle.center) >= distort_circle.r)){
                        if(rand()%2){
                            points.push_back(this_point);    
                        } 
                    }
                    else{
                        points.push_back(this_point);
                    }
                }
            }
        }
        return point_matrix(points);
    }
    point_matrix generate_randcircle_distortion(){
        point_matrix mt0 = this->simple_generate();
        
    }
};