#pragma once
#include <iostream>
#include <fstream>

class Affichable {

public:
	virtual void afficher(std::ostream& o) const = 0;
	virtual void changerCouleur(int codeCouleur) = 0;
};