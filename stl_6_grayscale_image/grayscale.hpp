
#include <array>
#include <cstdint>
#include <forward_list>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

constexpr size_t height = 3;
constexpr size_t width = 10;

void Show_vec(const std::vector<std::pair<uint8_t, uint8_t>> & );
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& );
std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& );

int main() {    
    std::array<std::array<uint8_t, width>, height> arr_23 = {{
        {0, 0, 0, 1, 1, 2, 3, 0, 0, 0},
        {0, 0, 4, 4, 4, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 1, 2, 2, 2, 2}}
    };

    std::array<uint8_t, width> arr_1 = {0, 0, 0, 1, 1, 2, 3, 0, 0, 0};
    std::vector<std::pair<uint8_t, uint8_t>> v_t;
    std::pair<uint8_t, uint8_t> p_t;
    auto x = arr_1[0];
    auto lambda = [x](auto y){ return x == y; };
    auto count = std::count(arr_1.begin(), arr_1.end(),arr_1[0]);
    auto count_2 = std::count(arr_1.begin(), arr_1.end(),lambda);
    std::cout << count << '\n';
    std::cout << count_2 << '\n';
    
    std::vector<std::pair<uint8_t, uint8_t>> v_T;
    v_T = compressGrayscale(arr_23);
    Show_vec(v_T);

    decompressGrayscale(v_T);

    return 0;
}