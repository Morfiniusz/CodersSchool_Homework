#include <iostream>
#include <string>
#include <algorithm>


bool isPalindrom(std::string );



int main(){

    std::string str = "No lemon, no melon";
    //std::string str = "Ala, ala";
    std::cout << std::boolalpha << isPalindrom(str) << '\n';

    return 0;
}