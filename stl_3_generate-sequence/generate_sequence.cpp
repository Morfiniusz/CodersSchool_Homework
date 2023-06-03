#include <iostream>
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    
    int x = step;
    std::vector<int> vec;
    for (int i = 0; i < count; ++i) {
        vec.push_back(step);
        step += x;
    }   
    return vec;
}

int main() {

    auto result = generateSequence(5, 3);

    for (auto el : result){
        std::cout << el <<  " ";
    }
    
    return 0;
}