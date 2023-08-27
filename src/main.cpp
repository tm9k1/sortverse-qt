#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& arr) {
    for(auto iter = arr.begin(); iter < arr.end(); iter++) {
        cout << *iter << ' ';        
    }
    cout << endl;
}

vector<int> merge(const vector<int>& arr1, const vector<int>& arr2) 
{
    vector<int> mergedArray(arr1.size() + arr2.size());
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

vector<int> mergeSort(const vector<int>& arr, int startIndex, int length) {
    if (length < 2) {
        if(length == 0) {
            return {};
        }
        vector<int> ret(length);
        int i=0;
        while(i < length) {
            ret[i] = arr[startIndex+i];
            i++;
        }
        return ret;
    }
    return merge(mergeSort(arr, startIndex, length/2), mergeSort(arr, startIndex + length/2, length/2));
}

vector<int> sort(vector<int>& arr) {
    cout << "Welcome to sorter!\n";
    return mergeSort(arr, 0, arr.size());
}


int main()
{

    vector<int> arr {5, 7, 1, 3, 8, 10, 11, 2};

    cout << "Starting with this array:\n";
    printArray(arr);
    cout << "Starting sort operation now..\n";
    vector<int> ans = sort(arr);
    cout << "Sorting completed. Here is the result:\n";
    printArray(ans);

    return 0;
}
