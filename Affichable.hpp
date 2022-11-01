#pragma once
#include <iostream>
#include <fstream>

class Affichable {

public:
	virtual void afficher(std::ofstream& o) const = 0;
	virtual void changerCouleur(std::ofstream& o, int codeCouleur) const = 0;
};