#include <bubbleSort.h>
#include <iostream>

extern "C" SortVersePlugin* instance() {
    return new BubbleSort();
}

std::vector<int> BubbleSort::sort(const std::vector<int>& arr) {
    std::cout << "Welcome to Bubble Sort!\n";
    std::vector<int> ans(arr);
    for (int i = 0; i < ans.size() ; i++) {
        for (int j = 0; j < ans.size() - i - 1; j++) {
            if (ans[j] > ans[j+1]) {
                int temp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = temp;
            }
        }
    }
    return ans;
}
