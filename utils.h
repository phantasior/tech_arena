#pragma once

struct Point {
    double _x, _y;

    Point(double x, double y) {
        _x = x;
        _y = y;
    }
};

double y(const Point& p1, const Point& p2, double x0);
