#include "schedule.hpp"
#include <chrono>
#include <functional>
#include <thread>
#include <string>



void schedule(std::function<void()> func, std::chrono::seconds t){
    std::this_thread::sleep_for (t);
    func();
}

void schedule(std::function<void(int)> func, std::chrono::seconds t, int x){
    std::this_thread::sleep_for (t);
    func(x);
}

void schedule(std::function<void(std::string,double)> func, std::chrono::seconds t,std::string s, double d){
    std::this_thread::sleep_for (t);
    func(s,d);
}