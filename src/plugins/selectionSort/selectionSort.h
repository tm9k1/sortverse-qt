#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <core/sortverseplugin.h>

class SelectionSort : public SortVersePlugin {
public:
    std::vector<int> sort(const std::vector<int>&) override;
};


#endif // SELECTIONSORT_H
