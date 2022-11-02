#include "Heros.hpp"

Heros::Heros(std::string nom, std::string nomJeu, std::string ennemi, std::vector<std::string> allies) :
	Personnage(nom, nomJeu), nomEnnemi_(ennemi), listeAllies_(allies) {};

//Constructeur de copie
Heros::Heros(const Heros& heros) : Personnage(heros.getNom(), heros.getTitre()),
nomEnnemi_(heros.nomEnnemi_), listeAllies_(heros.listeAllies_) {};

void Heros::afficher(std::ofstream& o) const
{
	this->Personnage::afficher(o);

	o << "Ennemi : " << nomEnnemi_ << std::endl;
	o << "Alliés : " << std::endl;

	for (const std::string& nomAllie : listeAllies_)
		o << "\t" << nomAllie << std::endl;
}
