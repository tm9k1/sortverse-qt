#ifndef MERGESORT_H
#define MERGESORT_H

#include <core/sortverseplugin.h>

class MergeSort : public SortVersePlugin {
public:
    MergeSort() {}
    std::vector<int> sort(const std::vector<int>&) override;
    std::vector<int> merge(const std::vector<int>& arr1, const std::vector<int>& arr2);
    std::vector<int> mergeSort(const std::vector<int>& arr, int startIndex, int length);
};


#endif // MERGESORT_H
