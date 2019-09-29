#include "duke.h"


Duke::Duke() {
	m_attack = "Duke Tax";
	m_defense = "Block Foreign Aid";
	m_art = "    _#_    \n   / # \\     { $ $ }  /n  | L |  \n  _\\ - / _  \n / \\_ / \\ \n/ _ / , , , , , \\_\\\n";
}
Duke::Duke(string art = "    _#_    \n   / # \\     { $ $ }  /n  | L |  \n  _\\ - / _  \n / \\_ / \\ \n/ _ / , , , , , \\_\\\n"){
	m_art = art;
	m_attack = "Duke Tax";
	m_defense = "Block Foreign Aid";
}

Duke::~Duke()
{
}


