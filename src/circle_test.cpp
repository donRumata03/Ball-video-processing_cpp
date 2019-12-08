#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <D:\Projects\Video_anal\Machine_Learning\src\Circle finder.cpp>
#include <D:\Projects\Video_anal\Machine_Learning\src\test_generator.cpp>

using namespace std;


int main(){
    ofstream f("D:/Projects/Video_anal/Machine_Learning/res/data_for_graphing/error_func_test.txt");
    Test_Generator t1(circle(point(0, 0), 100), point(-110, -110), point(110, 110), circle(point(0, 100), 100));
    point_matrix mt = t1.generate_random_distortion();
    mt.print();
    pms points = mt.get_points();
    pms new_poiints;
    point cent(0, 0);
    double err;
    for(double x = -200; x <= 200; x += 10){
        cout << x << " " << err << endl;
        err = error_function(points, circle(point(x, cent.y), 100));
        f << x << " " << err << endl;
    }
    f.close();
    system(python_command);
    _getch();
    return 0;
}