/* Note.h
Author: Joshua Prendergast */

#ifndef NOTE_H
#define NOTE_H

#include "Game.h"
#include "AnchorableEntity.h"
#include "RenderComponent.h"

#define NOTE_LEN 7

#define NOTE_MOD_NONE 0
#define NOTE_MOD_SHARP 1
#define NOTE_MOD_FLAT 2

namespace sight {

class Note : public AnchorableEntity {
public:
    Note(Game *game, Entity *parent, int value, int modifiers);
    ~Note();
    void setHighlight(bool highlight);
    void reposition();
    static std::string getNoteName(int value, int modifiers);
private:
    int value; /* Middle C is 0 */
    int modifiers;
    RenderComponent *marker;
    RenderComponent *label;
    static std::string NOTES[];
};

}

#endif // NOTE_H
