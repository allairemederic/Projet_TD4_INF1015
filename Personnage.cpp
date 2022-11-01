#include "Personnage.hpp"

Personnage::Personnage(std::string nom, std::string nomJeu) :
	nomPersonnage_(nom), titreParution_(nomJeu) {};

void Personnage::afficher(std::ofstream& o) const
{
	o << "Nom : " << nomPersonnage_ << std::endl;
	o << "Parution : " << titreParution_ << std::endl;
}

void Personnage::changerCouleur(std::ofstream& o, int codeCouleur) const
{
	o << "\033[" << codeCouleur << "m";
}

void Personnage::setNom(std::string nom)
{
	nomPersonnage_ = nom;
}

const std::string& Personnage::getNom() const
{
	return nomPersonnage_;
}

void Personnage::setTitre(std::string titre)
{
	titreParution_ = titre;
}

const std::string& Personnage::getTitre() const
{
	return titreParution_;
}