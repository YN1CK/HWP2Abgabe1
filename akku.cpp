#include "akku.h"

float akku::getKapazitaet() {
    return this->kapazitaet;
}

void akku::setKapazitaet(float capacity) {
    if ( capacity > 5000) {
        this->kapazitaet = 5000;
    }
    else {
        this->kapazitaet = capacity;
    }
}