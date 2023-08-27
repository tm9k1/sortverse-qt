#include "sorter.h"
#include <iostream>

std::vector<int> Sorter::sort(const std::vector<int>& vec) 
{
    std::cout << "Base class is triggered." << std::endl;
    return vec;
}
