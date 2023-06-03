#pragma once
#include <string>
#include <algorithm>
#include <ranges>
#include "palindrom.hpp"

bool isPalindrom(std::string testString) {

    //std::string testString;
    testString.erase(std::remove_if(testString.begin(), testString.end(), isspace), testString.end());
    std:: cout << testString << '\n';
    testString.erase(std::remove_if(testString.begin(),
                                    testString.end(),
                                    [](auto const & c) -> bool {
                                        return !std::isalnum(c);
                                    }),
                                    testString.end()
                                    );
    std::transform(testString.begin(), testString.end(), testString.begin(), [](auto & c){return std::tolower(c);});
    std:: cout << testString << '\n';
    return  std::equal(testString.begin(), testString.end(), testString.rbegin());
}
// + testString.size()/2