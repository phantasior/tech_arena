#pragma once

struct Point {
    double x, y;
};

float dist(const Point& lhs, const Point& rhs);

double y(const Point& p1, const Point& p2, double x0);