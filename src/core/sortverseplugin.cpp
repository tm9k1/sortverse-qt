#include "sortverseplugin.h"
#include <iostream>

std::vector<int> SortVersePlugin::sort(const std::vector<int>& vec) 
{
    std::cout << "Base class is triggered." << std::endl;
    return vec;
}
