#include "Heros.hpp"

Heros::Heros(std::string nom, std::string nomJeu, std::string ennemi, std::vector<std::string> allies) :
	Personnage(nom, nomJeu), nomEnnemi_(ennemi), listeAllies_(allies) {};

void Heros::afficher(std::ofstream& o) const
{
	this->Personnage::afficher(o);

	o << "Ennemi : " << nomEnnemi_ << std::endl;
	o << "Alliés : " << std::endl;

	for (const std::string& nomAllie : listeAllies_)
		o << "\t" << nomAllie << std::endl;
}
