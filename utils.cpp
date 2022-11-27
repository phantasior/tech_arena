#include "utils.h"
#include <cmath>

double y(const Point& p1, const Point& p2, double x0) {
    return (x0 - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
}

