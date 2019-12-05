#ifndef HELP_FUNC_CPP
#define HELP_FUNC_CPP

#include <math.h>
#include <vector>


using namespace std;

// Types
#define list vector<int>
#define pms vector<point>

// Constants
#define POINT_DIST_POW (1/2)
#define MATRIX_DEBUG_MODE 0

// Functions
#define sqr(x) (x * x)
#define dist(a, b) (sqrt(sqr((a.x - b.x)) + sqr((a.y - b.y))))
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))


class point{
    public:
    double x;
    double y;
    point(double _x, double _y){
        x = _x;
        y = _y;
    }
    point(int _x, int _y){
        x = _x;
        y = _y;
    }
    point(){

    }
    bool operator == (point &p2){
        return (x == p2.x) && (y == p2.y);
    }
    point copy(){
        point new_point;
        new_point.x = x;
        new_point.y = y; 
        return new_point;
    }
};


class point_matrix{
    public:
        bool ** mt;
        int h;
        int w;
        int first_x;
        int last_x;
        int first_y;
        int last_y;

        point_matrix(int _h, int _w, point first_p){
            construct_by_false(_h, _w, first_p);
        }

        point_matrix(pms &points){
            int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
            for(int i = 0; i < points.size(); i++){
                minx = min(minx, points.at(i).x);
                miny = min(miny, points.at(i).y);
                maxx = max(maxx, points.at(i).x);
                maxy = max(maxy, points.at(i).y);
            }
            int mt_h = maxy - miny + 1;
            int mt_w = maxx - minx + 1;
            #if MATRIX_DEBUG_MODE
            
            cout << "Max x: " << maxx << endl;
            cout << "Max y: " << maxy << endl;
            cout << "Min x: " << minx << endl;
            cout << "Min y: " << miny << endl;
            
            #endif
     
            point first {(double)minx, (double)miny};
            construct_by_false(mt_h, mt_w, first);
            for(int pn = 0; pn < points.size(); pn++){
                mt[(int)points.at(pn).x - first_x][(int)points.at(pn).y - first_y] = true;
            }
        }
        void construct_by_false(int _h, int _w, point first_p){
            w = _w;
            h = _h;
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
        void print(){
            cout << "Matrix: " << endl;
            cout << w << " " << h << endl;
            for(int y = 0; y < h; y++){
                for(int x = 0; x < w; x++){
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
        bool at(point p){
            if (p.x < first_x || p.x >= last_x || p.y >= last_y || p.y < first_y) return false;
            return mt[(int)p.x - first_x][(int)p.y - first_y];
        }
};


void print_point_vector(pms v){
    for(int i = 0; i < v.size(); i++){
        cout << "(" << v.at(i).x << ", " << v.at(i).y << ") ";
    }
    cout << endl;
}


double tanx(point p1, point p2, point p3){

}


double point_segment_dist(){

}


#endif