#include <iostream>
#include <forward_list>
#include <string>
#include <deque>
#include <algorithm>
#include <cctype>

void Show(const std::deque<std::string> & deq) {
    for( const auto & el : deq) {
        std::cout << el << '\n';
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string> & f_list){
    f_list.sort();
    std::deque<std::string> d_list;
    for(const auto & el : f_list) {
        d_list.push_back(el);
    }

    std::sort(d_list.begin(), d_list.end(), [](const std::string & str1,const std::string & str2){return str1.size() < str2.size();});
    return d_list;
}

int main() {
    std::forward_list<std::string> forward_list {"Three", "One", "Four", "Two", "Five", "A" , "a"};
    Show(lengthSort(forward_list));

    return 0;
}