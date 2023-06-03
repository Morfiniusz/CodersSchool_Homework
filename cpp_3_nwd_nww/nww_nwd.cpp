#include <iostream>

/*
void check_d(int x, int y){
    int z;
    if (x < y){        
        y = z;
        y = x;
        x = z;
    }
}
*/

int NWD(int first_d, int second_d){
    int rest;
    if (first_d < 0){
        first_d *= -1;
    }
    if (second_d < 0){
        second_d *= -1;
    }
    if(first_d != 0 and second_d != 0){        
        while(second_d != 0 ){
            rest = first_d%second_d;
            first_d = second_d;
            second_d = rest;
        }
        return first_d;
    }
    else if(first_d != 0 and second_d == 0){
        return first_d;
    } 
    else if(first_d == 0 and second_d != 0){
        return second_d;
    } 
    else{
        return 0;
    }
}

int NWW(int first_w, int second_w){
    if (first_w < 0){
        first_w *= -1;
    }
    if (second_w < 0){
        second_w *= -1;
    }
    if (first_w != 0 and second_w != 0){
        return (first_w*second_w)/NWD(first_w,second_w);
    }
    else{
        return 0;
    }        
}


int main(){
    int a;
    int b;
    /*
    std::cout << "Insert first number : ";
    std::cin >> a;
    std::cout << "Insert first second : ";
    std::cin >> b;
    */
    //std::cout << "NWW(-5 -20) = " << NWW(-5, -20) << "\n";
    std::cout << "NWD(0, 1) = " << NWD(0, 1) << "\n";
    std::cout << "NWD(1, 0) = " << NWD(1, 0) << "\n";

    return 0;
}