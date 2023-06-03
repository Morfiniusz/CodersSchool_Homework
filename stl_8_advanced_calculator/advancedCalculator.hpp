#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <cmath>
#include <iostream>


enum class ErrorCode {
    Ok,
    BadCharacter,
    BadFormat,
    DivideByO,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

bool checkInputFormat(std::string str3) {
    int operationCounter = 0;
    for (auto it = str3.begin(); it != str3.end(); ++it) {
        if (*it == ',') {
            return false;
        }
        if (it == str3.begin() && !isdigit(*it) && *it != '-') {
            return false;
        }
        if((*it == '+') || (*it == '-') || (*it == '*') || (*it == '/') || (*it == '^') || (*it == '%') || (*it == '$') || (*it == '!')) {
            ++operationCounter;
        }
    }
    if (operationCounter > 3) {
        return false;
    }
    return true;
}

auto checkOperation(std::string & str1) {
    for(auto it = str1.begin(); it != str1.end(); ++it) {
        if((((*it == '+') || (*it == '-') || (*it == '*') || (*it == '/') || (*it == '^') || (*it == '%') || (*it == '$')) && (it != str1.begin())) || (*it == '!')) {
        return it;
        }
    }
    return str1.end();
}

bool isNumber(const std::string & str2) {
    for (auto it = str2.begin(); it != str2.end();++it){
        if (!std::isdigit(*it) && (*it != '.') && (*it != '-')) {
            return false;
        }
    }
    return true;
}

bool isInteger(const std::string & str4) {
    for (auto it = str4.begin(); it != str4.end(); ++it) {
        if (*it == '.') {
            return false;
        }
    }
    return true;
}

double doMath (const char & c,const auto & first,const auto & second) {
    std::map<char, std::function<double(double, double)>> mathMap {
        {'+', [](const double & x, const double & y){ return x + y;}},
        {'-', [](const double & x, const double & y){ return x - y;}},
        {'*', [](const double & x, const double & y){ return x * y;}},
        {'/', [](const double & x, const double & y){ return x / y;}},
        {'^', [](const double & x, const double & y){ return pow(x, y);}},
        {'$', [](const double & x, const double & y){ return pow(x, 1/y);}},
        {'%', [](const int & x, const int & y){ return x % y;}}
    };
    return mathMap[c](first, second);
}

ErrorCode process(std::string input, double * out) {
    std::string first;
    std::string second;

    auto isSpace = [](unsigned char x){ return std::isspace(x);};
    auto operation = checkOperation(input);
    std::remove_copy_if(input.begin(), operation, std::back_inserter(first),isSpace);
    std::remove_copy_if(std::next(operation), input.end(), std::back_inserter(second),isSpace);

    if(!isNumber(first) || !isNumber(second)){
        std::cout << "Bład: zły znak" << '\n';
        return ErrorCode::BadCharacter;
    }

    if (!checkInputFormat(input)){
        std::cout << "Błąd: zły format operacji" << '\n';
        return ErrorCode::BadFormat;
    }

    if((*operation == '/') && (std::stod(second) == 0)) {
        std::cout << "Błąd: dzielenie przez 0" << '\n';
        return ErrorCode::DivideByO;
    }

    if((*operation == '$') && (std::stod(first) < 0)) {
        std::cout << "Błąd: pierwiastek z negatywnej liczby" << '\n';
        return ErrorCode::SqrtOfNegativeNumber;
    }

    if((*operation == '%') && (!isInteger(first) || !isInteger(second))) {
        std::cout << "Błąd: modulo z liczby zmiennoprzecinkowej" << '\n';
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    std::cout << "Format operacji jest prawidłowy" << '\n';
    *out = doMath(*operation,std::stod(first),std::stod(second));
    return ErrorCode::Ok;
}

int main() {
    std::cout << "operacja: ";
    std::string task;
    std::getline(std::cin, task);


    double result = 0;
    process(task, &result);
    std::cout << result << '\n';


    return 0;
}
