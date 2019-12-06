#ifndef HELP_FUNC_CPP
#define HELP_FUNC_CPP

#include <math.h>
#include <vector>


using namespace std;

// Types
#define list vector<int>
#define pms vector<point>

// Constants
#define POINT_DIST_POW (((double)1/2))
#define MATRIX_DEBUG_MODE 0
#define LINE_DEBUG_MODE 0
#define ERROR_FUNCTION_DEBUGGING_MODE 0

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
    void print(){
        cout << "point: x = " << x << ", y = " << y << "  ";
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
            cout << w << " x " << h << endl;
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
        pms get_points(){
            pms points;
            for(int x = 0; x < w; x++){
                for(int y = 0; y < h; y++){
                    if(mt[x][y]){
                        points.push_back(point(x, y));
                    }
                }
            }
            return points;
        }
        point_matrix copy(){
            pms points = this->get_points();
            return point_matrix(points);
        }
};


class line{
    public:
    double k, b;
    double A, B, C;
    line (double _k, double _b){
        k = _k;
        b = _b;
    }
    line (point p1, point p2){
        if (p1 == p2){
            cout << "ERROR!!! Can`t define line by one point!!!" << endl;
            return;
        }
        A = p1.y - p2.y;
        B = p1.x - p2.x;
        C = p1.x * p2.y - p2.x * p1.y;
        #if LINE_DEBUG_MODE
        cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
        cout << A << " " << B << " " << C << endl;
        #endif
    }
    line  (double _A, double _B, double _C){
        A = _A;
        B = _B;
        C = _C;
    }
    line(){

    }
    
    double f(double x){
        if (B == 0){
            cout << "INFINITY!!!";
            return x;
        }
        return (A * x + C) / B;
    }

    bool operator == (line &line2){
        return ((k == line2.k) && (b == line2.b)) || ((A == line2.A) && (B == line2.B) && (C == line2.C));
    }
};


class segment{
    public:
    point p1;
    point p2;
    line l;
    segment(point _p1, point _p2){
        p1 = _p1;
        p2 = _p2;
        l = line(p1, p2);
    }
    segment(){
    
    }
    double length(){
        return dist(p1, p2);
    }
};


class circle{
    public:
    double x, y, r;
    point center;
    template <class E, class T, class H>
    circle(E _x, T _y, T _r){
        x = (double)_x;
        y = (double)_y;
        r = (double)_r;
        center = point(x, y);
    }
    template<class G>
    circle (point cent, G _r){
        x = cent.x;
        y = cent.y;
        r = _r;
        center = cent.copy();
    }
    circle(){

    }
    circle copy(){
        return circle(center, r);
    }
};


void print_point_vector(pms v){
    for(int i = 0; i < v.size(); i++){
        cout << "(" << v.at(i).x << ", " << v.at(i).y << ") ";
    }
    cout << endl;
}


double point_line_dist(point p, line l){
    return abs(l.A * p.x + l.B * p.y + l.C) / sqrt(sqr(l.A) + sqr(l.B));
}


double point_circle_dist(point p, circle c){
    return(abs(dist(p, c.center) - c.r));
}


#endif