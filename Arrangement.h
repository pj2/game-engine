/* Arrangement.h
Author: Joshua Prendergast */

#ifndef ARRANGEMENT_H
#define ARRANGEMENT_H

#include <vector>

namespace sight {

class Arrangement {
public:
    Arrangement(int bars);
    ~Arrangement();
    void randomize();
    void clear();
    std::vector<int> &getNoteValues();
private:
    std::vector<int> noteValues;
    int beatsPerBar;
    int beatLength;
    int length;
};

}

#endif // ARRANGEMENT_H
