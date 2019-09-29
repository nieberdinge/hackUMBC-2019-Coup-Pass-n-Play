#ifndef CARD_H
#define CARD_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class Card {
public:
	//constructor
	Card();
	//overloaded
	Card(string attackAction, string defenseAction, string art);
	//virtual destructor implement in child classes
	virtual ~Card() {};
	string getAttack();
	string getDefense();
	string getArt();
	void setArt(string);
	void setDefense(string);
	void setAttack(string);
protected:
	string m_attack;
	string m_defense;
	string m_art;
};
#endif 