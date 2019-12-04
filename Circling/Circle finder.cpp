#include <vector>
#include <math.h>
#include <Help_func.cpp>

using namespace std;



double error_function(list &points, double r, point center){
    list edges = detect_edges(points);
    double err = 0;
    for(int i = 0; i < edges.size(); i++){
        point this_point {edges.at(i)};
        err += pow(dist(center, ))
    }
}


bool ** make_mt(list &poits){
    
}


list detect_edges(list &points){
    
}