#include <iostream>
#include "utils.h"
#include <vector>
#include <fstream>

using namespace std;

const double STEP = 15;

std::vector<Point> points;

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

    std::vector<pair<Point, Point>> ans;

    for (double i = minx; i < maxx; i += STEP) {
        double l = i;
        double r = std::min(i + STEP, maxx);

        double miny = INT_MAX, maxy = -INT_MAX;
        for (int j = 0; j < n - 1; ++j) {
            if (points[j].x <= l && l <= points[j + 1].x) {
                double cur = y(points[j], points[j + 1], l);
                miny = std::min(miny, cur);
                maxy = std::max(maxy, cur);
            }

            if (points[j].x <= r && r <= points[j + 1].x) {
                double cur = y(points[j], points[j + 1], r);
                miny = std::min(miny, cur);
                maxy = std::max(maxy, cur);
            }
        }

        ans.push_back({{l, miny}, {r, maxy}});

    }


    std::cout << std::fixed << std::setprecision(9);
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i].first.x << ' ' << ans[i].first.y - 1 << ' ' << ans[i].second.x << ' ' << ans[i].second.y + 1 << '\n';
    }
    
}