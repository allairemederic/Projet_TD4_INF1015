#include "VilainHeros.hpp"

VilainHeros::VilainHeros(Vilain vilain, Heros heros) :
	Personnage(vilain.getNom() + "-" + heros.getNom())

void Vilain::afficher(std::ofstream& o) const
{
	this->Personnage::afficher(o);

	o << "Objectif : " << phraseObjectif_ << std::endl;
}