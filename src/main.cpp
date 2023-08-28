#include <iostream>
#include <vector>
#include <core/pluginloader.h>
#include <core/sortverseplugin.h>

using namespace std;

void printArray(vector<int>& arr) {
    for(auto iter = arr.begin(); iter < arr.end(); iter++) {
        cout << *iter << ' ';        
    }
    cout << endl;
}

int main()
{
    std::cout << "Helloooooooo 1" << std::endl;
    PluginLoader* loader = PluginLoader::instance();
    std::cout << "Helloooooooo 2" << std::endl;
    vector<int> arr {5, 7, 1, 3, 8, 10, 11, 2};

    cout << "Starting with this array:\n";
    printArray(arr);
    cout << "Starting sort operation now..\n";
    vector<int> ans;
    for (SortVersePlugin* plugin : PluginLoader::instance()->getPlugins()) {
        ans = plugin->sort(arr);
        printArray(ans);
    }

    // vector<int> ans = loader->mergeSort(arr);
    // cout << "Sorting completed. Here is the result:\n";
    // printArray(ans);

    return 0;
}