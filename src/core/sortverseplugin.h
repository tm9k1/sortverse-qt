#ifndef SORTVERSEPLUGIN_H
#define SORTVERSEPLUGIN_H
#include <vector>

/*Base class that provides basic template for a sorting algorithm 
  that may be implemented as superclass of SortVersePlugin class.
*/

class SortVersePlugin {

public:
    SortVersePlugin();
    virtual std::vector<int> sort(const std::vector<int>&);
};

#endif // SORTVERSEPLUGIN_H
