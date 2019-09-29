#include "card.h"

//default constructor
Card::Card() {}

Card::Card(string attackAction, string defenseAction, string art) {
	m_attack = attackAction;
	m_defense = defenseAction;
	m_art = art;
}
string Card::getAttack() {
	return m_attack;
}
string Card::getDefense() {
	return m_defense;
}
string Card::getArt() {
	return m_art;
}

void Card::setArt(string art){
	m_art = art;
}

void Card::setDefense(string def){
	m_defense = def;
}

void Card::setAttack(string att){
	m_attack = att;
}
