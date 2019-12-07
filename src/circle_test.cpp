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
    Test_Generator t1(circle(point(0, 0), 100), point(-110, -110), point(110, 110), circle(point(0, 100), 100));
    point_matrix mt = t1.generate_random_distortion();
    mt.print();
    pms points = mt.get_points();
    pms new_poiints;
    point cent(0, 0);
    double err;
    for(double x = -200; x <= 200; x += 1){
        cout << x << " " << err << endl;
        err = error_function(points, circle(point(x, cent.y), 100));
        f << x << " " << err << endl;
    }
    f.close();
    system("C:\\Users\\Vova\\AppData\\Local\\Programs\\Python\\Python37-32\\python.exe D:\\Libraries\\PycharmProjects\\Podgonyator\\Video+Photo\\cpp\\Graph_bulider\\err_debug.py");
    _getch();
    return 0;
}