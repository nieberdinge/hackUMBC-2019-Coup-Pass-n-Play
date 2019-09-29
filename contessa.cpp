#include "contessa.h"
Contessa::Contessa() {
	m_attack = "None";
	m_defense = "Block Assassination";
	m_art = "    ooo    \n   OOOOO   \n  O u u O  \n  (  i  )  \n OO\\ u / OO \n / \\_ / \\ \n/ _ /     \\_\\\n";
}
Contessa::Contessa(string art = "    ooo    \n   OOOOO   \n  O u u O  \n  (  i  )  \n OO\\ u / OO \n / \\_ / \\ \n/ _ /     \\_\\\n") {
	m_art = art;
	m_attack = "None";
	m_defense = "Block Assassination";
}


Contessa::~Contessa()
{
}


