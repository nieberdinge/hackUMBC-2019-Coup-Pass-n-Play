#include "captain.h"
Captain::Captain() {
	m_attack = "Steal";
	m_defense = "Block Steal";
	m_art = "    ___    \n   / L\\L\\   \n  / \\T X / \\  \n  || L \\ |  \n  _\\ ^ / _  \n / |\\_/| \\ \n/ _/| / |\\_\\\n";
}
Captain::Captain(string art= "    ___    \n   / L\\L\\   \n  / \\T X / \\  \n  || L \\ |  \n  _\\ ^ / _  \n / |\\_/| \\ \n/ _/| / |\\_\\\n"){
	m_art = art;
	m_attack = "Steal";
	m_defense = "Block Steal";
}

Captain::~Captain()
{
}


