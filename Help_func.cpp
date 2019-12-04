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
            
        }
};
