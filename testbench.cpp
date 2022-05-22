/*
 * Testbench für die Aufgabe 1.2 b) 
 * der ersten Abgabe in HWP2 SoSe2022
 */

#include <iostream>
#include "drohne.h"

int main()
{
	drohne drohny;
	drohny.aktuellPosition();
	drohny.drohneLaden(6032);
	drohny.restKapazitaet(); 
	drohny.steige(4);
	drohny.fliegVorwaerts(2);
	drohny.fliegLinks(2);
	drohny.fliegRueckwaerts(1);
	drohny.fliegRechts(4);
	drohny.sinke(3);
	drohny.aktuellPosition();
	drohny.restKapazitaet();
	return 1;
}