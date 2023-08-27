#ifndef SORTER_H
#define SORTER_H
#include <vector>

/*Base class that provides basic template for a sorting algorithm 
  that may be implemented as superclass of Sorter class.
*/

class Sorter {

public:
    virtual std::vector<int> sort(const std::vector<int>&);
};

#endif // SORTER_H
