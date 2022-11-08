#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include <iostream>
#include "bibliotheque_cours.hpp"

#include "Personnage.hpp"
#include "Heros.hpp"
#include "Vilain.hpp"
#include "VilainHeros.hpp"

using namespace std;

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}

void lectureHeros(std::vector<Heros>& vecHeros, ifstream& fichier) {

	int nbHeros = lireUintTailleVariable(fichier);

	for (int i = 0; i < nbHeros; i++) {

		std::string nomHeros = lireString(fichier);
		std::string titreParution = lireString(fichier);
		std::string nomEnnemi = lireString(fichier);

		std::vector<std::string> vectAllies;

		int nbAllies = lireUintTailleVariable(fichier);

		for (int j = 0; j < nbAllies; j++) {

			vectAllies.push_back(lireString(fichier));
		}

		Heros tempHeros = Heros(nomHeros, titreParution, nomEnnemi, vectAllies);
		vecHeros.push_back(tempHeros);
	}
}

void lectureVilain(std::vector<Vilain>& vecVilain, ifstream& fichier) {

	int nbVilains = lireUintTailleVariable(fichier);

	for (int i = 0; i < nbVilains; i++) {

		std::string nomVilain = lireString(fichier);
		std::string titreParution = lireString(fichier);
		std::string objectif = lireString(fichier);

		Vilain tempVilain = Vilain(nomVilain, titreParution, objectif);
		vecVilain.push_back(tempVilain);
	}
}

int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	//testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)

	std::vector<Heros> vecHeros;
	std::vector<Vilain> vecVilains;
	std::vector<Personnage*> vecPersos;

	lectureHeros(vecHeros, fichierHeros);
	lectureVilain(vecVilains, fichierVilains);

	for (Heros& h : vecHeros) {

		h.changerCouleur(36);
		h.afficher(cout);
		cout << trait << endl;

		vecPersos.push_back(&h);
	}

	for (Vilain& v : vecVilains) {

		v.changerCouleur(91);
		v.afficher(cout);
		cout << trait << endl;

		vecPersos.push_back(&v);
	}

	for (Personnage* p : vecPersos) {

		p->afficher(cout);
		cout << trait << endl;
	}

	VilainHeros vh = VilainHeros(vecVilains.at(0), vecHeros.at(0));

	vh.changerCouleur(95);
	vh.afficher(cout);

	cout << "\033[0m";

}
