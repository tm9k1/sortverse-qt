#include <mergeSort.h>
#include <iostream>

extern "C" SortVersePlugin* instance() {
    std::cout << "instance from mergeSort DLL called!" << std::endl;
    return new MergeSort();
}

std::vector<int> MergeSort::merge(const std::vector<int>& arr1, const std::vector<int>& arr2) 
{
    std::vector<int> mergedArray(arr1.size() + arr2.size());
    int i = 0, j = 0, idx = 0;
    while((i < arr1.size()) && (j < arr2.size()) ) {
        if(arr1[i] < arr2[j]) {
            mergedArray[idx++] = arr1[i++];
        } else {
            mergedArray[idx++] = arr2[j++];
        }
    }
    while((i < arr1.size())) {
        mergedArray[idx++] = arr1[i++];
    }
    while((j < arr2.size())) {
        mergedArray[idx++] = arr2[j++];
    }

    return mergedArray;
}

std::vector<int> MergeSort::mergeSort(const std::vector<int>& arr, int startIndex, int length) {
    if (length < 2) {
        if(length == 0) {
            return {};
        }
        std::vector<int> ret(length);
        int i=0;
        while(i < length) {
            ret[i] = arr[startIndex+i];
            i++;
        }
        return ret;
    }
    return merge(mergeSort(arr, startIndex, length/2), mergeSort(arr, startIndex + length/2, length/2));
}

std::vector<int> MergeSort::sort(const std::vector<int>& arr) {
    std::cout << "Welcome to sorter!\n";
    return mergeSort(arr, 0, arr.size());
}
