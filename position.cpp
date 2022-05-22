#include "position.h"

void position::setPosition(int x, int y, int z) {
    this->aktuellPosition = (koordinaten) {x, y, z};
}

koordinaten position::getPosition() {
    return this->aktuellPosition;
}