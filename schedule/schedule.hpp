#pragma once
#include <chrono>
#include <functional>
#include <thread>
#include <string>

template<typename Func, typename Type, typename... Variables>
void schedule(Func f, Type t, Variables... v) {
    std::this_thread::sleep_for(t);
    f(std::forward<Variables>(v)...);
}

void schedule(std::function<void()> , std::chrono::seconds );
void schedule(std::function<void(int)> , std::chrono::seconds , int );
void schedule(std::function<void(std::string,double)> , std::chrono::seconds ,std::string , double );