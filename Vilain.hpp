#pragma once
#include "Personnage.hpp"
#include <vector>

class Vilain : virtual public Personnage {

public:
	Vilain(std::string nom, std::string nomJeu, std::string objectif);
	~Vilain() = default;

	void afficher(std::ofstream& o) const override;

private:
	std::string phraseObjectif_;
};