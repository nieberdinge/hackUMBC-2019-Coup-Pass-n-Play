#include "Player.h"
#include "card.h"

/*
_________________\n
|               |\n
|               |\n
|               |\n
|     DEAD      |\n
|     CARD      |\n
|               |\n
|               |\n
|_______________|\n
*/

Player::Player() {
	m_name = "Plant";
	m_coin = 0;
	m_cardOne = nullptr;
	m_cardTwo = nullptr;
}

Player::Player(string name, Card *card1, Card *card2) {
	m_name = name; 
	m_coin = 2;
	m_cardOne = card1;
	m_cardTwo = card2;
};

string Player::getName() { return m_name; }
void Player::displayCards() {
	cout << m_cardOne->getArt() << endl;
	cout << m_cardTwo->getArt() << endl;
}

void Player::displayInventory() {
	displayCards();
	cout << "Number of coins you have: " << m_coin << endl;

}
void Player::stolen() {
	if(m_coin < 2){
		throw 1;
	}
	--m_coin;
	m_coin--;
}

void Player::addCoin(){
	m_coin++;
}

Card * Player::getCardOne(){
	return m_cardOne;
}

Card * Player::getCardTwo(){
	return m_cardTwo;
}

int Player::getCoins(){
	return m_coin;
}

void Player::loseCoin(){
	m_coin--;
}

void Player::loseCard() {
	system("CLS");
	cout << m_name << " please look at the screen/nPress any key when ready" << endl;
	cin;
	displayCards();

	
	int ans; 
	do{
		cout << "Please choose a card to get rid of" << endl;
		cin >> ans;
	} while (ans < 1 || ans > 2);
	if (ans == 1) {
		m_cardOne->setArt("_________________\n|               |\n|               |\n|               |\n| DEAD | \n| CARD | \n|               |\n|               |\n| _______________ | \n");
		m_cardOne->setAttack("DEAD");
		m_cardOne->setDefense("DEAD");
	}else{
		m_cardTwo->setArt("_________________\n|               |\n|               |\n|               |\n| DEAD | \n| CARD | \n|               |\n|               |\n| _______________ | \n");
		m_cardTwo->setAttack("DEAD");
		m_cardTwo->setDefense("DEAD");
	}
	

}
bool Player::isDead() {
	if (m_cardOne->getAttack() == "DEAD" && m_cardTwo->getAttack() == "DEAD") {
		return true;
	}
	return false;
}

int Player::turn() {
	int ans; 
	do {
		cout << m_name << ", what would you like to do? " << endl;
		cout << "1. Take Income" << endl
			<< "2. Take Foreign Aid" << endl
			<< "3. Coup a player" << endl
			<< "4. Duke Tax" << endl
			<< "5. Assassinate" << endl
			<< "6. Exchange" << endl
			<< "7. Steal" << endl;
		cin >> ans;
	
	} while (ans < 1 || ans > 7);

	return ans;


}