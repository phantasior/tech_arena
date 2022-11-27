#include "utils.h"

#include <fstream>
#include <iostream>
#include <vector>

std::vector<Point> points;

const double STEP = 1;

bool cmp(const Point& lhs, const Point& rhs) {
    if (lhs.x == rhs.x) {
        return lhs.y < rhs.y;
    } else {
        return lhs.x < rhs.x;
    }
}

void print(const std::vector<Point>& points) {
    for (auto i : points) {
        std::cout << "(" << i.x << ' ' << i.y << ") ";
    }

    std::cout << '\n';
}

int main() {
    freopen("../tests/02.txt", "r", stdin);

    int n;
    double c1, c2;
    std::cin >> n >> c1 >> c2;
    points.resize(n);

    double minx = INT_MAX, maxx = -INT_MAX;
    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        points[i] = {x, y};

        minx = std::min(minx, x);
        maxx = std::max(maxx, x);

    }

    std::vector<Point> spoints = points;
    std::sort(spoints.begin(), spoints.end(), &cmp);
    // print(spoints);

    std::vector<Points> ans;

    for (double i = minx; i < maxx; i += STEP) {
        double l = i;
        double r = std::min(i + STEP, maxx);

        for (int j = 0; j < n - 1; ++j) {
            if (points[j].x <= l && l <= points[j + 1].x) {
                
            }

            if (points[j].x <= r && r <= points[j + 1].x) {

            }
        }
    }


    std::cout << std::fixed << std::setprecision(9);
    std::cout << minx << ' ' << maxx << '\n';
    
}