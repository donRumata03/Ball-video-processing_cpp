#include <math.h>
#include <vector>

using namespace std;

// Types
#define list vector<int>
#define pms vector<point>

// Constants
#define POINT_DIST_POW (1/10)

// Functions
#define sqr(x) (x * x)
#define dist(a, b) (sqrt(sqr(a.x - b.x) + sqr(a.y - b.x)))


struct point{
    int x;
    int y;
};
