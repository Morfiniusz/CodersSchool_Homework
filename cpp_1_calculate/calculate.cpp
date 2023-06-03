#include <iostream>
#include <string>

std::string calculate (const std::string& command, int first, int second){

    if(command =="add"){       
        return std::to_string(first + second);
    }
    else if(command == "substract"){
        return std::to_string(first - second);
    }
    else if(command == "multiply"){
        return std::to_string(first * second);
    }  
    else if(command == "divide"){
        if(second != 0){
            return std::to_string(first / second);
        }
        else{
            return "You can't divide by 0";
        }   
    }
    else{
        return "Invalid data";
    }
}

int main(){

    auto result = calculate("add", 2,3);
    std::cout << result << "\n";
    result = calculate("substract", 0,0);
    std::cout << result << "\n";
    result = calculate("multiply", -10,20);
    std::cout << result << "\n";
    result = calculate("divide", 0,20);
    std::cout << result << "\n";
    result = calculate("hello", 2,3);
    std::cout << result << "\n";
    return 0;
}
