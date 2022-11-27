#include "utils.h"

#include <fstream>
#include <iostream>
#include <vector>

std::vector<Point> points;

int main() {
    freopen("../tests/07.txt", "r", stdin);

    int n;
    double c1, c2;
    std::cin >> n >> c1 >> c2;
    points.resize(n);

    double minx = INT_MAX, miny = INT_MAX, maxx = -INT_MAX, maxy = -INT_MAX;

    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        points[i] = {x, y};

        minx = std::min(minx, x);
        miny = std::min(miny, y);
        maxx = std::max(maxx, x);
        maxy = std::max(maxy, y);
    }

    std::cout << 1 << '\n';
    std::cout << std::fixed << std::setprecision(9);
    std::cout << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << '\n';
}