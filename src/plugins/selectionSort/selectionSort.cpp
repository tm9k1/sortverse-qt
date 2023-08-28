#include <selectionSort.h>
#include <iostream>

extern "C" SortVersePlugin* instance() {
    return new SelectionSort();
}

std::vector<int> SelectionSort::sort(const std::vector<int>& arr) {
    std::cout << "Welcome to Selection Sort!\n";
    std::vector<int> array(arr);
    for (int i = 0; i < array.size() ; i++) {
        int min_elem = array[i];
        int min_elem_idx = i;
        for (int j = i; j < array.size(); j++) {
            if (array[j] < min_elem) {
                min_elem = array[j];
                min_elem_idx = j;
            }
        }
        int temp = array[i];
        array[i] = min_elem;
        array[min_elem_idx] = temp; 
    }
    return array;
}
