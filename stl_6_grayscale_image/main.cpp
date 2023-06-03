#pragma once
#include <iostream>
#include <array>
#include <cstdint>
#include <vector>
#include "grayscale.hpp"
#include <utility>
#include <algorithm>

void Show_arr(std::array<std::array<uint8_t, width>, height>  a_t_t);

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& a_T) {
    std::vector<std::pair<uint8_t, uint8_t>> v_t;
    std::pair<uint8_t, uint8_t> p_t;
    for (const auto & el_height : a_T) {
        p_t.first = el_height.front();
        for (const auto & el_width : el_height) {
            if (el_width == p_t.first) {
                ++p_t.second;
            }
            else {
                v_t.push_back(p_t);
                p_t.first = el_width;
                p_t.second = 1;
            }
        }
        v_t.push_back(p_t);
        p_t.second = 0;
    }
    v_t.shrink_to_fit();
    return v_t;
}




void Show_vec(const std::vector<std::pair<uint8_t, uint8_t>> & vec_Pair) {
    for (const auto & el : vec_Pair) {
        std::cout << "{ " <<unsigned(el.first) << ", " << unsigned(el.second) << " }";
    }
    std::cout << '\n';
}


void Show_arr(std::array<std::array<uint8_t, width>, height>  a_t_t) {
    for (auto & el : a_t_t) {
        for (auto & el_2 : el){
            std::cout << unsigned(el_2) << " ";
        }
        std::cout << '\n';
    }

}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& v_T){
    std::array<std::array<uint8_t, width>, height> a_t;
    int row = 0;
    int column = 0;
    for (auto & el_v : v_T) {
        for (auto i = 0; i < el_v.second; ++i){
            a_t[row][column + i] = el_v.first;
        }
        column += el_v.second;
        if(column == width) {
            ++row;
            column = 0;
        }
    }
    Show_arr(a_t);
    return a_t;
}

// std::vector<std::pair<uint8_t, uint8_t>> cG(const std::array<uint8_t> a_T) {
//     std::vector<std::pair<uint8_t, uint8_t>> v_t;
//     std::pair<uint8_t, uint8_t> p_t;
//     p_t.first = el_height.front();
//     auto count = std::count_if(a_t.begin(), a_T.end(),[pt.first](auto x){return pt.first == x})
    

// }



