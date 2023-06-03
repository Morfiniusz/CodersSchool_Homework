#include <iostream>
#include <vector>

int maxOfVector(std::vector<int> num) {

    int new_max = num[0];
    for (int i = 0; i < num.size(); ++i) {
        if(new_max < num[i]) {
            new_max = num[i];                     
        }
    }  
    return new_max;
}

int main() {

    std::vector<int> numbers = {6, 0, 12, 54, -11, 78};
    auto result = maxOfVector(numbers);

    std::cout << result << '\n';

    return 0;
}