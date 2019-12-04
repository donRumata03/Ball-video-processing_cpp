#include <vector>
#include <math.h>
#include <iostream>
#include <Help_func.cpp>

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


bool ** make_mt(pms &points){
    int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
    for(int i = 0; i < points.size(); i++){
        minx = min(minx, points.at(i).x);
        miny = min(miny, points.at(i).y);
        maxx = max(minx, points.at(i).x);
        maxy = max(maxy, points.at(i).y);
    }

    #if DEBUG_MODE
    cout << "Max x: " << maxx << endl;
    cout << "Max y: " << maxy << endl;
    cout << "Min x: " << minx << endl;
    cout << "Min y: " << miny << endl;
    #endif

    int mt_h = maxy - miny + 1;
    int mt_w = maxx - minx + 1;
    point first {minx, miny};
    bool ** mt = new bool* [mt_w];
    
}


pms detect_edges(pms &points){
    
}