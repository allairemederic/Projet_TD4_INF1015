#pragma once
#include "Personnage.hpp"
#include <vector>

class Vilain : virtual public Personnage {

public:
	Vilain(std::string nom, std::string nomJeu, std::string objectif);

	Vilain(const Vilain& vilain); //Constructeur de copie

	~Vilain() = default;

	void afficher(std::ofstream& o) const override;

protected:
	std::string phraseObjectif_;
};