#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <core/sortverseplugin.h>

class QuickSort : public SortVersePlugin {
public:
    int partition(std::vector<int>& arr, int start, int end);
    void quickSort(std::vector<int>& arr, int start, int end);
    std::vector<int> sort(const std::vector<int>&) override;
};


#endif // QUICKSORT_H
