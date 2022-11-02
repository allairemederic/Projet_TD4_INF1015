#include "VilainHeros.hpp"

VilainHeros::VilainHeros(Vilain vilain, Heros heros) :
	Personnage(vilain.getNom() + "-" + heros.getNom(), vilain.getTitre() + "-" + heros.getTitre()),
	Vilain(vilain), Heros(heros)
{
	missionSpeciale_ = Vilain::phraseObjectif_ + " dans le monde de " + heros.getTitre();
}

void VilainHeros::afficher(std::ostream& o) const
{
	this->Personnage::afficher(o);
	this->Vilain::afficher(o);
	this->Heros::afficher(o);

	o << "Mission spéciale : " << missionSpeciale_ << std::endl;
}