#include <iostream>
#include <vector>

int addEven (const std::vector <int>& numbers) {
    
    int sum = 0;
    for(const auto& num : numbers){
        if(num%2 == 0){
            sum = sum + num;
        }
    }
    return sum;
}

int main() {


    std::vector<int> vec {1, 2, 3, 4, 5};
    auto result = addEven(vec);

    std::cout << result << '\n';


    return 0;
}