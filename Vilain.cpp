#include "Vilain.hpp"

Vilain::Vilain(std::string nom, std::string nomJeu, std::string objectif) :
	Personnage(nom, nomJeu), phraseObjectif_(objectif) {};

//Constructeur de copie
Vilain::Vilain(const Vilain& vilain) : Personnage(vilain.getNom(), vilain.getTitre()),
phraseObjectif_(vilain.phraseObjectif_){};

void Vilain::afficher(std::ostream& o) const
{
	this->Personnage::afficher(o);

	afficherInfos(o);
}

void Vilain::afficherInfos(std::ostream& o) const
{
	o << "Objectif : " << phraseObjectif_ << std::endl;
}

const std::string Vilain::getObjectif() const
{
	return phraseObjectif_;
}