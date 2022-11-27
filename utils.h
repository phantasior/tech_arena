#pragma once

struct Point {
    double _x, _y;

    Point(double x, double y) {
        _x = x;
        _y = y;
    }
};

float dist(const Point& lhs, const Point& rhs);

double y(Point& p1, Point& p2, double x0) {
    return (x0 - p1._x) * (p2._y - p1._y) / (p2._x - p1._x) + p1._y;
}