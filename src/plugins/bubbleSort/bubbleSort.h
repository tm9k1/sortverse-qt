#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <core/sortverseplugin.h>

class BubbleSort : public SortVersePlugin {
public:
    std::vector<int> sort(const std::vector<int>&) override;
};


#endif // BUBBLESORT_H
