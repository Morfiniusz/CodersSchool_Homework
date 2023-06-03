#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <algorithm>
#include <list>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>, std::deque<int>);


int main() {

    std::string str = "223a34455a6677a";
    str.erase(std::unique(str.begin(), str.end()), str.end());
    std::cout << str << '\n';
    //removeDuplicateAndTranformToMap()

    return 0;
}
