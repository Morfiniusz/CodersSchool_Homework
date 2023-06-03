#include <iostream>
#include <vector>
#include <list>

int maxOfVector(const std::vector<int>& num) {
    std::list<int> list;

    for (size_t i = 0; i < num.size(); i++) {
        list.push_back(num[i]);
    }

    for (const auto& el_l : list) {
        list.sort(std::greater<int>());
    }

    return list.front();
}

int main() {

    std::vector<int> numbers = {6, 78, 12, 54, -11, 0};
    auto result = maxOfVector(numbers);

    std::cout << result << '\n';

    return 0;
}