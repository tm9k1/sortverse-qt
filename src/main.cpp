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
    // PluginLoader* loader = PluginLoader::instance();
    // QPluginLoader will be used
    vector<int> arr {5, 7, 1, 3, 8, 10, 11, 2};
    // vector<int> arr {886, 378, 271, 510, 993, 151, 930, 955, 740, 684, 278, 173, 401, 404, 635, 294, 895, 505, 748, 76, 335, 582, 259, 929, 150, 684, 904, 713, 413, 591, 563, 891, 172, 437, 497, 638, 953, 162, 145, 241, 936, 466, 446, 310, 781, 120, 48, 261, 882, 234, 811, 768, 321, 248, 399, 139, 837, 348, 765, 77, 198, 56, 1, 555, 406, 237, 952, 760, 183, 597, 247, 548, 558, 902, 409, 852, 306, 112, 126, 407, 675, 941, 849, 836, 425, 556, 167, 421, 845, 366, 499, 70, 250, 327, 964, 582, 275, 519, 238, 825};

    cout << "Starting with this array:\n";
    printArray(arr);
    cout << "Starting sort operations now..\n";
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
