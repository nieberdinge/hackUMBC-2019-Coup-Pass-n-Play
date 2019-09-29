#include "ambassador.h"

Ambassador::Ambassador() {
	m_attack = "Exchange";
	m_defense = "Block Stealing";
	m_art = "   *****   \n  *******  \n  \\ | > O|/  \n  < | < | >  \n  _\\ s / _  \n / ^^\\_ / ^^\\ \n/ ^ / ^^^^^\\^\\\n";
}
Ambassador::Ambassador(string art ="   *****   \n  *******  \n  \\ | > O|/  \n  < | < | >  \n  _\\ s / _  \n / ^^\\_ / ^^\\ \n/ ^ / ^^^^^\\^\\\n" ) {
	m_art = art;
	m_attack = "Exchange";
	m_defense = "Block Stealing";
}
Ambassador::~Ambassador(){};



/*

  *****   \n 
 *******  \n
\\ | > O|/  \n
< | < | >  \n
_\\ s / _  \n
/ ^^\\_ / ^^\\ \n
/ ^ / ^^^^^\\^\\\n"

*/