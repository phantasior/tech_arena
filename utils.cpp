#include "utils.h"
#include <cmath>

double y(const Point& p1, const Point& p2, double x0) {
    if (p1.x > p2.x) {
        return (x0 - p2.x) * (p1.y - p2.y) / (p1.x - p2.x) + p2.y;
    }
    return (x0 - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
}

