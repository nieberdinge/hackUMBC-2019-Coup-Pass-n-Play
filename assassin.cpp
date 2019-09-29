#include "assassin.h"
Assassin::Assassin() {
	m_attack = "Assassinate";
	m_defense = "None";
	m_art = "    _()       \n   / ___\\      \n  / v v \\     \n  | c |  \\ \n  _\\ ^ / _   ))\n / \\_ / \\  --\n/ _ / \\_\\ / ^ 3\n";
}
Assassin::Assassin(string art = "    _()       \n   / ___\\      \n  / v v \\     \n  | c |  \\ \n  _\\ ^ / _   ))\n / \\_ / \\  --\n/ _ / \\_\\ / ^ 3\n")  {
	m_attack = "Assassinate";
	m_defense = "None";
	m_art = art;
}

Assassin::~Assassin()
{
}


