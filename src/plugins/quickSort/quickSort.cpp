#include <quickSort.h>
#include <iostream>

extern "C" SortVersePlugin* instance() {
    return new QuickSort();
}

int QuickSort::partition(std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int i = start;
    for (int j = start ; j < end ; j++) {
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = i + 1;
        }
    }
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    return i;
}

void QuickSort::quickSort(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p-1);
        quickSort(arr, p+1, end);
    }
}

std::vector<int> QuickSort::sort(const std::vector<int>& arr) {
    std::cout << "Welcome to Quick Sort!\n";
    std::vector<int> array(arr);
    quickSort(array, 0, array.size()-1);
    return array;
}
