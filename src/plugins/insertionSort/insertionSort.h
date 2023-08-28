#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <core/sortverseplugin.h>

class InsertionSort : public SortVersePlugin {
public:
    std::vector<int> sort(const std::vector<int>&) override;
};


#endif // INSERTIONSORT_H
