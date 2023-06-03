#include "arithmeticAverage.hpp"
#include <iostream>
#include <vector>

int main () {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 3, 4};
    std::cout << ArithmeticAverage(vec1, vec2) << '\n';

    std::vector<int> vec3 = {7, 4, 3, 13};
    std::vector<int> vec4 = {17, 6, 2, -2};
    std::cout << Distance(vec3, vec4) << '\n';
    return 0;
}