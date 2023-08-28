#include <mergeSort.h>
#include <iostream>

extern "C" SortVersePlugin* instance() {
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

std::vector<int> MergeSort::mergeSort(const std::vector<int>& arr, int startIndex, int endIndex) {
    int length = endIndex - startIndex;
    if (length < 2) {
        if(length == 0) {
            return {};
        }
        return {arr[startIndex]};
    }
    return merge(mergeSort(arr, startIndex, startIndex + length/2), mergeSort(arr, startIndex + length/2, endIndex));
}

std::vector<int> MergeSort::sort(const std::vector<int>& arr) {
    std::cout << "Welcome to Merge Sort!\n";
    return mergeSort(arr, 0, arr.size());
}
