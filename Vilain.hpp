#pragma once
#include "Personnage.hpp"
#include <vector>

class Vilain : virtual public Personnage {

public:
	Vilain(std::string nom, std::string nomJeu, std::string objectif);

	Vilain(const Vilain& vilain); //Constructeur de copie

	~Vilain() = default;

	void afficher(std::ostream& o) const override;

	const std::string getObjectif() const;

protected:
	void afficherInfos(std::ostream& o) const;

private:
	std::string phraseObjectif_;
};