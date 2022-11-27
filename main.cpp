#include "utils.h"

#include <fstream>
#include <iostream>
#include <vector>

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
    freopen("../tests/04.txt", "r", stdin);

    int n;
    double c1, c2;
    std::cin >> n >> c1 >> c2;
    points.resize(n);


    std::vector<std::pair<Point, Point>> ans;

    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        points[i] = {x, y};

    }

    std::vector<Point> spoints = points;
    sort(spoints.begin(), spoints.end(), &cmp);
    print(spoints);

    for (int i = 0 ; i < n; ++i) {
        int j = i;
        while (spoints[i].x == spoints[j].x) {
            j++;
        }

        if (j == n) break;

        double miny = spoints[i].y;
        for (int k = 0; k < n - 1; ++k) {
            if (points[k].x <= spoints[i].x && spoints[i].x <= points[k + 1].x) {
                miny = std::min(miny, points[k].y);
            }
        }


        // j - is the lowest

        double maxy = spoints[j].y;
        for (int k = 0; k < n - 1; ++k) {
            if (points[k].x <= spoints[j].x && spoints[j].x <= points[k + 1].x) {
                maxy = std::max(maxy, points[k].y);
            }
        }

        // std::vector<Point> tmp = {points[i], spoints[j]};
        // sort(tmp.begin(), tmp.end(), &cmp);
        ans.push_back({{spoints[i].x, miny}, {spoints[j].x, maxy}});
        i = j - 1;
    }

    std::cout << std::fixed << std::setprecision(9);

    std::cout << ans.size() << '\n';
    for (auto i : ans) {
        std::cout << i.first.x << ' ' << i.first.y << ' ' << i.second.x << ' ' << i.second.y << '\n';
    }

}