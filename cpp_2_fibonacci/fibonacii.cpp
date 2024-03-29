#include <iostream>

int fibonacci_iterative (int sequence){

   int first = 0;
   int second = 1;
   if(sequence == 0){
       return 0;
   }
   else if (sequence == 1){
       return 1;
   }
   else if (sequence >= 2){
       int third = 0;
       for (int i = 2; i <= sequence + 1; ++i){
            third = first + second;
            second = first;
            first = third;            
       }
       return first;
   }   
}

int fibonacci_recursive(int sequence){
    if(sequence == 0){
        return 0;
    }
    else if (sequence == 1){
        return 1;
    }
    else{
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    }
}

int main(){
    /*
    int n = 0;
    std::cout << "Podaj ktora liczbe ciagu fibonacciego mam wyswietlic : ";
    std::cin >> n;
    std::cout <<"Iteracyjnie :" << fibonacci_iterative(n) << "\n";
    std::cout <<"Rekurencyjnie :" << fibonacci_recursive(n) << "\n";
    */

    std::cout << fibonacci_iterative(15) << "\n";
    std::cout << fibonacci_recursive(15) << "\n";
    return 0;
}