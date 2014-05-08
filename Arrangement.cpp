/* Arrangement.cpp
Author: Joshua Prendergast */

#include "Arrangement.h"
#include <cstdlib>

namespace sight {

Arrangement::Arrangement(int bars) : beatsPerBar(4), beatLength(4), length(bars * beatsPerBar) {
}

Arrangement::~Arrangement() {
}

void Arrangement::randomize() {
    int i;
    noteValues.clear();

    for (i = 0; i < length; i++) {
        noteValues.push_back(rand() % 14);
    }
}

std::vector<int> &Arrangement::getNoteValues() {
    return noteValues;
}

}