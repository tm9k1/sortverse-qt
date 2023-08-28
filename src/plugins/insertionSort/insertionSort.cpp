#include <insertionSort.h>
#include <iostream>

extern "C" SortVersePlugin* instance() {
    return new InsertionSort();
}

std::vector<int> InsertionSort::sort(const std::vector<int>& arr) {
    std::cout << "Welcome to Insertion Sort!\n";
    std::vector<int> array(arr);
    for (int i = 1; i < array.size() ; i++) {
        int j = i;
        int B = array[i];
        while(j > 0 && array[j-1] > B) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = B;
    }
    return array;
}
