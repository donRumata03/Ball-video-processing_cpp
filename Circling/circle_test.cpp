#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Circling\Circle finder.cpp>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Help_func.cpp>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Circling\test_generator.cpp>


using namespace std;


int main(){
    ofstream f("D:\\Libraries\\PycharmProjects\\Podgonyator\\Video+Photo\\cpp\\res\\data_for_graphing\\error_func_test.txt");
    Test_Generator t1(circle(point(0, 0), 100), point(-110, -110), point(110, 110));
    point_matrix mt = t1.simple_generate();
    mt.print();
    pms points = mt.get_points();
    pms new_poiints;
    point cent(0, 0);
    double err;
    for(double r = 5; r <= 300; r += 0.1){
        Test_Generator new_gen(circle(point(0, 0), r), point(-110, -110), point(110, 110));

        point_matrix new_mt = new_gen.simple_generate();
        // new_mt.print();
        err = error_function(points, circle(cent, r));
        // cout << r << " " << err << endl;
        f << r << " " << err << endl;
    }
    f.close();
    _getch();
    return 0;
}