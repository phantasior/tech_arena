#include "utils.h"

#include <cmath>

float dist(const Point& lhs, const Point& rhs) {
    return  (rhs.x - lhs.x)*(rhs.x - lhs.x) + (rhs.y - lhs.y)*((rhs.y - lhs.y));
}