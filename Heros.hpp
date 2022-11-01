#pragma once
#include "Personnage.hpp"
#include <vector>

class Heros : virtual public Personnage {

public:
	Heros(std::string nom, std::string nomJeu, std::string ennemi, std::vector<std::string> allies);
	~Heros() = default;

	void afficher(std::ofstream& o) const override;

private:
	std::string nomEnnemi_;
	std::vector<std::string> listeAllies_;
};