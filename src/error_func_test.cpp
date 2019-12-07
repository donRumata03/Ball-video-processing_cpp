#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Circling\Circle finder.cpp>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Help_func.cpp>
#include <D:\Libraries\PycharmProjects\Podgonyator\Video+Photo\cpp\Circling\test_generator.cpp>


using namespace std;


int main(){
    Test_Generator t1(circle(point(0, 0), 30), point(-1000, -35), point(10000, 35), circle(point(0, 20), 30));
    point_matrix mt = t1.generate_moon_distortion();

    mt.print();
    _getch();
    return 0;
}