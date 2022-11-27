#include "utils.h"

#include <iostream>

int main() {
    Point a = {0, 0};
    Point b = {1, 1};
    std::cout << dist(a, b);
}