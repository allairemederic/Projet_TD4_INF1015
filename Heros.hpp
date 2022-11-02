#pragma once
#include "Personnage.hpp"
#include <vector>

class Heros : virtual public Personnage {

public:
	Heros(std::string nom, std::string nomJeu, std::string ennemi, std::vector<std::string> allies);
	
	Heros(const Heros& heros); //Constructeur de copie

	~Heros() = default;

	void afficher(std::ostream& o) const override;

protected:
	std::string nomEnnemi_;
	std::vector<std::string> listeAllies_;
};