#include <iostream>
#include <vector>
#include <memory>
#pragma once

std::vector <std::shared_ptr<int>> generate(int );

void print(std::vector <std::shared_ptr<int>>  );

void add10(std::vector <std::shared_ptr<int>> );

void sub10( int* const );

void sub10(std::vector <std::shared_ptr<int>> );
