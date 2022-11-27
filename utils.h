#pragma once

struct Point {
    double x, y;
};

float dist(const Point& lhs, const Point& rhs);

double y(const Point& p1, const Point& p2, double x0) {
    return (x0 - p1.x) * (p2.y - p1.y) / (p2.x - p1.x) + p1.y;
}