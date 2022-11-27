#include "utils.h"
#include <cmath>

double y(Point& p1, Point& p2, double x0) {
    if (p1.x > p2.x) {
        Point k = p1;
        p1 = p2;
        p2 = k;
    }
    
    return (x0 - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
}

