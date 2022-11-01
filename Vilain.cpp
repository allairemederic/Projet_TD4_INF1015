#include "Vilain.hpp"

Vilain::Vilain(std::string nom, std::string nomJeu, std::string objectif) :
	Personnage(nom, nomJeu), phraseObjectif_(objectif) {};

void Vilain::afficher(std::ofstream& o) const
{
	this->Personnage::afficher(o);

	o << "Objectif : " << phraseObjectif_ << std::endl;
}
