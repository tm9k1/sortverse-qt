#include <mergeSort.h>
#include <iostream>

extern "C" void hello(void)
{
    std::cout << "Hello from the Plugin\n";
}

std::vector<int> MergeSort::sort(const std::vector<int>& vec) {
    std::cout << "MergeSort from inside the class called!" << std::endl;
    return vec;
}
