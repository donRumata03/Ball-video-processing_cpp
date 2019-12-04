#ifndef HELP_FUNC_CPP
#define HELP_FUNC_CPP

#include <math.h>
#include <vector>


using namespace std;

// Types
#define list vector<int>
#define pms vector<point>

// Constants
#define POINT_DIST_POW (1/10)
#define DEBUG_MODE 1

// Functions
#define sqr(x) (x * x)
#define dist(a, b) (sqrt(sqr(a.x - b.x) + sqr(a.y - b.x)))
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))


struct point{
    double x;
    double y;
};


class point_matrix{
    public:
        bool ** mt;
        double h;
        double w;
        double first_x;
        double last_x;
        double first_y;
        double last_y;

        point_matrix(int _h, int _w, point first_p){
            mt = new bool* [_w];
            for(int x = 0; x < _w; x++){
                mt[x] = new bool [_h];
                for (int y = 0 ; y < _h; y++){
                    mt[x][y] = false;
                }
            }
            first_x = first_p.x;
            first_y = first_p.y;
            last_x = first_x + w;
            last_y = first_y + h;
        }

        point_matrix(pms &points){
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
            point_matrix(mt_h, mt_w, first);
        }
        void print(){
            cout << "Matrix: " << endl;
            for(int x = 0; x < w; x++){
                for(int y = 0; y < h; y++){
                    if (mt[x][y]){
                        cout << 1;
                    }
                    else{
                        cout << 0;
                    }
                    cout << " ";
                }
                cout << endl;
            }
            cout << "... End of matrix!" << endl;
        }
};


#endif