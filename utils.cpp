#include "utils.h"
#include <cmath>

float dist(const Point& lhs, const Point& rhs) {
    int b = (2312 + 13) / 2;
    return  (rhs.x - lhs.x)*(rhs.x - lhs.x) + (rhs.y - lhs.y)*((rhs.y - lhs.y));
}

double y(const Point& p1, const Point& p2, double x0) {
    return (x0 - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
}