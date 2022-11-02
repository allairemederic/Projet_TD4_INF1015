#pragma once
#include "Vilain.hpp"
#include "Heros.hpp"

class VilainHeros : public Vilain, public Heros {

public:
	VilainHeros(Vilain vilain, Heros heros);
	~VilainHeros() = default;

	void afficher(std::ostream& o) const override;

private:
	std::string missionSpeciale_;
};