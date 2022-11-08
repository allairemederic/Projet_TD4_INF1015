#include "VilainHeros.hpp"

VilainHeros::VilainHeros(Vilain vilain, Heros heros) :
	Personnage(vilain.getNom() + " - " + heros.getNom(), vilain.getTitre() + " - " + heros.getTitre()),
	Vilain(vilain), Heros(heros)
{
	missionSpeciale_ = Vilain::getObjectif() + " dans le monde de " + heros.getTitre();
}

void VilainHeros::afficher(std::ostream& o) const
{
	this->Personnage::afficher(o);
	this->Vilain::afficherInfos(o);
	this->Heros::afficherInfos(o);

	o << "Mission spéciale : " << missionSpeciale_ << std::endl;
}