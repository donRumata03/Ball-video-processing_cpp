#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Help_func.cpp>

using namespace std;


pms sort_verts(pms points){
    pms sorted_points;
    point this_point = points.at(0);
    point first_point = points.at(0);
    bool flag = true;
    while(!(this_point == first_point) || flag){
        
        flag = false;
    }
}


pms generate_neighboors(point p){
    pms n;
    point point_up = p.copy();
    point point_down = p.copy();
    point point_left = p.copy();
    point point_right = p.copy(); 

    point_up.y++;
    point_down.y--;
    point_left.x--;
    point_right.y++;
    n.push_back(point_right);
    n.push_back(point_left);
    n.push_back(point_up);
    n.push_back(point_down);
    return n;
}


pms generate_neighboors(point p, int w, int h){
    pms n;
    point point_up = p.copy();
    point point_down = p.copy();
    point point_left = p.copy();
    point point_right = p.copy(); 

    point_up.y++;
    point_down.y--;
    point_left.x--;
    point_right.y++;

    n.push_back(point_right);
    n.push_back(point_left);
    n.push_back(point_up);
    n.push_back(point_down);
    return n;
}


pms detect_edges(pms &points){
    point_matrix mt = point_matrix(points);
    point this_point;
    pms result;
    for(int i = 0; i < points.size(); i++){
        this_point = points.at(i);
        pms n = generate_neighboors(this_point);
        bool has_no_zero_neighboors = true;
        for(int pnn = 0; pnn < n.size(); pnn++){
            point pn = n.at(pnn);
            if (!mt.at(pn)){
                has_no_zero_neighboors = false;
                break;
            }
        }
        if(mt.at(this_point) && (!has_no_zero_neighboors)){
            result.push_back(this_point);
        }
    }
    return result;
}


double error_function(pms &points, circle c){
    pms edges = detect_edges(points);
    #if ERROR_FUNCTION_DEBUGGING_MODE
    print_point_vector(edges);
    #endif
    double err = 0;
    for(int i = 0; i < edges.size(); i++){
        point this_point = point(edges.at(i).x, edges.at(i).y);
        err += pow(point_circle_dist(this_point, c), POINT_DIST_POW);
    }
    
    return err;
}