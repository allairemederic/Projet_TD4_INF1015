#pragma once
#include "Affichable.hpp"

class Personnage : public Affichable {

public:
	Personnage(std::string nom, std::string nomJeu);
	~Personnage() = default;

	void afficher(std::ostream& o) const override;
	void changerCouleur(int codeCouleur) override;

	void setNom(std::string nom);
	const std::string& getNom() const;
	void setTitre(std::string titre);
	const std::string& getTitre() const;

private:
	std::string nomPersonnage_;
	std::string titreParution_;
	int couleur_;
};