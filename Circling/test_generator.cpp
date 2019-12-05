#include <vector>
#include <math.h>
#include <iostream>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Help_func.cpp>

using namespace std;

#define r 10
#define x_cent 20
#define y_cent 20
#define x_0 0
#define x_1 40
#define y_0 0
#define y_1 40

pms points;
point this_point;


int main(){
    point cent_point;
    cent_point.x = x_cent;
    cent_point.y = y_cent;
    for(int x = x_0; x < x_1; x++){
        for(int y = y_0; y < y_1; y++){
            this_point.x = x;
            this_point.y = y;
            if (dist(cent_point, this_point) <= r){
                points.push_back(this_point);
            }
        }
    }
    point_matrix mt(points);
    mt.print();
    cout << endl;
    system("pause");
    return 0;
}