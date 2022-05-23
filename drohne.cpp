#include "drohne.h"

drohne::drohne() {
    // Neuer Akku wurde noch nicht geladen
    akku batterie;
    batterie.setKapazitaet(0);
    this->batterie = batterie;

    // Drohne wird auf dem Boden am Startpunkt positioniert
    position Position;
    Position.setPosition(0, 0, 0);
    this->drohnenPos = Position;
}

// Richtungsfunktionen
void drohne::steige(int m) {

    for (; m > 0; --m) {

        // Bewegung
        this->drohnenPos.setPosition(this->drohnenPos.getPosition().x,
                                     this->drohnenPos.getPosition().y,
                                     this->drohnenPos.getPosition().z + 1);

        // Energieabzug
        this->verbrauch(1);
    }


}

void drohne::sinke(int m) {

    for (; m > 0; --m) {

        // Bewegung
        this->drohnenPos.setPosition(this->drohnenPos.getPosition().x,
                                     this->drohnenPos.getPosition().y,
                                     this->drohnenPos.getPosition().z - 1);

        // Energieabzug
        this->verbrauch(1);
    }
}

void drohne::fliegVorwaerts(int m) {

    for (; m > 0; --m) {

        // Bewegung
        this->drohnenPos.setPosition(this->drohnenPos.getPosition().x + 1,
                                     this->drohnenPos.getPosition().y,
                                     this->drohnenPos.getPosition().z);

        // Energieabzug
        this->verbrauch(1);
    }
}

void drohne::fliegRueckwaerts(int m) {

    for (; m > 0; --m) {

        // Bewegung
        this->drohnenPos.setPosition(this->drohnenPos.getPosition().x - 1,
                                     this->drohnenPos.getPosition().y,
                                     this->drohnenPos.getPosition().z);

        // Energieabzug
        this->verbrauch(1);
    }
}

void drohne::fliegLinks(int m) {

    for (; m > 0; --m) {

        // Bewegung
        this->drohnenPos.setPosition(this->drohnenPos.getPosition().x,
                                     this->drohnenPos.getPosition().y - 1,
                                     this->drohnenPos.getPosition().z);

        // Energieabzug
        this->verbrauch(1);
    }
}

void drohne::fliegRechts(int m) {

    for (; m > 0; --m) {

        // Bewegung
        this->drohnenPos.setPosition(this->drohnenPos.getPosition().x,
                                     this->drohnenPos.getPosition().y + 1,
                                     this->drohnenPos.getPosition().z);

        // Energieabzug
        this->verbrauch(1);
    }
}

// Systemfunktionen
void drohne::verbrauch(int m) {

    this->batterie.setKapazitaet(this->batterie.getKapazitaet() - 300 * m);
    
    // Wenn all, dann all und nicht überall :-P
    if (this->batterie.getKapazitaet() < 0) {
        this->batterie.setKapazitaet(0);
    }

    // Absturz
    if (!this->batterie.getKapazitaet()) {
        this->drohnenPos.setPosition(this->drohnenPos.getPosition().x,
                                        this->drohnenPos.getPosition().y,
                                        0);
        std::cout << "Warnung: Akku erschöpft!" << std::endl;
        std::cout << "(" << this->drohnenPos.getPosition().x << "|" << this->drohnenPos.getPosition().y << ")" << std::endl;
    }
}

// Drohne laden
void drohne::drohneLaden(int cap) {
    this->batterie.setKapazitaet(cap);
}

// Statusfunktionen
void drohne::restKapazitaet() {
    std::cout << "Akku: " << this->batterie.getKapazitaet() << "mAh" << std::endl;
}

void drohne::aktuellPosition() {
    std::cout << "Position: " << 
            this->drohnenPos.getPosition().x << " | " << 
            this->drohnenPos.getPosition().y << " | " << 
            this->drohnenPos.getPosition().z << std::endl;
}
