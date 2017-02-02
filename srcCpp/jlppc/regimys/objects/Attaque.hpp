
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include <iostream>
#include "../../includeAll.hxx"

using namespace std;

class Attaque : public RegimysObject{
public:
	virtual ~Attaque(){}
	Attaque(string nom, int puissance, Type type, int precision, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite);
	virtual void effetAvant(Pokemon &atk, Pokemon &def) = 0;
	virtual void effetApres(Pokemon &atk, Pokemon &def) = 0;
	void healPP(){pp = ppMax;}
	int attack(Pokemon &atk, Pokemon &def) final;
	virtual void siEchoue(Pokemon &atk, Pokemon &def){}
protected:
	string nom;
	int puissance;
	int priorite;
	int precision;
	Type type;
	bool special;
	bool status;
	int part = 0;
	int pp;
	int ppMax;
	int chanceDeCoups;
	bool rateJamais;
	int pvPerdus = 0;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */