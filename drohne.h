#ifndef DROHNE_H
#define DROHNE_H

// andere includes
#include <iostream>

// Teilobjekte
#include "akku.h"
#include "position.h"

class drohne {

public:
	// Konstruktor
	drohne();

	// Richtungsfunktionen
	void steige(int m);
	void sinke(int m);
	void fliegVorwaerts(int m);
	void fliegRueckwaerts(int m);
	void fliegLinks(int m);
	void fliegRechts(int m);

	// Systemfunktionen
	void verbrauch(int m);
	void drohneLaden(int cap);

	// Statusfunktionen
	void restKapazitaet();
	void aktuellPosition();	

private:
	void verbrauch();

	akku batterie;
	position drohnenPos;
};

#endif//DROHNE_H
