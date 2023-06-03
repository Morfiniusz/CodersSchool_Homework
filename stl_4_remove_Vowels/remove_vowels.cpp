#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void Show(const std::vector<std::string>& vec_show) {
    for(auto el_vec_show : vec_show) {
        std::cout << el_vec_show << ' ';
    }
    std::cout << "\n";
}

std::string VecToSring(const std::vector<std::string>& vec_toStr) {
    std::string str;
    for (auto el_vec_toStr : vec_toStr) {
        str.append(el_vec_toStr);
    }
    return str;
}

std::vector<std::string> removeVowels(std::vector<std::string>& vec_remove) {
    std::vector<std::string> vowels {"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"};
    std::vector<std::string> temp , vecToReturn;

    for( auto el_vec_remove : vec_remove) {
        for( auto it : el_vec_remove) {
            temp.push_back(std::string(1,it));
            for ( auto it_temp : temp) {
                for ( auto it_vowels : vowels) {
                    if (it_temp == it_vowels) {
                        temp.erase(std::remove(temp.begin(),temp.end(), it_temp),temp.end());
                    }
                }
            }
        }
        vecToReturn.push_back(VecToSring(temp));
        vecToReturn.shrink_to_fit();
        temp.erase(temp.begin(),temp.end());
    }
    return vecToReturn;
}

int main() {

    std::vector<std::string> vec { 
        {"Ala ma kota"},
        {"Alice has a cat"},
        {"Ala ma kota, a Sierotka Marysia"},
        {"ABCDERFGHIJK LMNOUPRS YYYY XXX ZZZ AAA BB CCC"}, 
        {"AaUuOoIiUuYy"}};
    Show(removeVowels(vec));

    return 0;
}