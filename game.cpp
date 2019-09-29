#include <iostream>
#include <vector>
#include <stdlib.h>    
#include <time.h>     
#include <fstream>

#include "Player.h"
#include "card.h"
#include "ambassador.h"
#include "captain.h"
#include "assassin.h"
#include "contessa.h"
#include "duke.h"

using namespace std;

std::string getFileContents(std::ifstream&);   

int main() {
	srand(time(NULL));
	rand() % 15 + 1;

	std::vector<Card*> deck;


	//Duke
	std::ifstream duke("duke.txt");            
	std::string Art1 = getFileContents(duke);  
	for (int i = 0; i < 3; i++) {
		Card* newCard = new Duke(Art1);
		deck.push_back(newCard);
	}
	duke.close();

	//Captian
	std::ifstream captian("captain.txt");
	std::string Art2 = getFileContents(captian);
	for (int i = 0; i < 3; i++) {
		Card* newCard = new Captain(Art2);
		deck.push_back(newCard);
	}
	captian.close();

	//Assassin
	std::ifstream assassin("assassin.txt");
	std::string Art3 = getFileContents(assassin);
	for (int i = 0; i < 3; i++) {
		Card* newCard = new Assassin(Art3);
		deck.push_back(newCard);
	}
	assassin.close();

	//ambassador
	std::ifstream ambassador("ambassador.txt");
	std::string Art4 = getFileContents(ambassador);
	for (int i = 0; i < 3; i++) {
		Card* newCard = new Ambassador(Art4);
		deck.push_back(newCard);
	}
	ambassador.close();

	//Contessa
	std::ifstream contessa("contessa.txt");
	std::string Art5 = getFileContents(contessa);
	for (int i = 0; i < 3; i++) {
		Card* newCard = new Contessa(Art5);
		deck.push_back(newCard);
	}
	contessa.close();

	/*
	for (int i = 0; i < 15; i++) {
		cout << deck.at(i)->getArt() << endl;
	}
	*/

	int numPlayers;
	std::vector<Player*> players;
	std::cout << "Welcome to pass and play Coup!" << std::endl;
	std::cout << "How many player do you have? " << std::endl;
	cin >> numPlayers;
	players.resize(numPlayers);
	string name;

	//Makes all the players
	for (int i = 0; i < numPlayers; i++) {
		cout << "Welcome player " << i + 1 << "!\nWhat is your name? ";
		cin >> name;
		int rad;
		do {
			rad = rand() % deck.size();
		} while (deck.at(rad) == nullptr);
		Card* card1 = deck.at(rad);
		deck.at(rad) = nullptr;

		do {
			rad = rand() % deck.size();
		} while (deck.at(rad) == nullptr);
		Card* card2 = deck.at(rad);
		deck.at(rad) = nullptr;


		Player *newPlayer = new Player(name, card1, card2);
		players.at(i) = newPlayer;
	}

	//INITAL SET UP DONE 

	bool gameWon = 0;
	int turn = 0;
	while (!gameWon) {
		if (turn >= players.size())
			turn = 0;
		if (!players.at(turn)->isDead()) {
			cout << "It is " << players.at(turn)->getName() << "'s turn. \nPlease pass the device.\nPress any button to continue." << endl;
			cin;
			system("CLS");
			players.at(turn)->displayInventory();
			int action;
			if (players.at(turn)->getCoins() > 9) {
				cout << "You have to many coins, you must coup this turn. " << endl;
				action = 3;
			}
			else {
				action = players.at(turn)->turn();
			}


			switch (action) {
				//Income
			case 1:
				cout << "1 coin has been added to your purse." << endl;
				players.at(turn)->addCoin();
				break;
				//Foreign Aid
			case 2:
				cout << players.at(turn)->getName() << "is trying to take Foreign Aid. Does any person want to block this? (y/n)" << endl;
				char ans;
				cin >> ans;
				if (ans == 'y') {
					cout << "Current Player: Would you like to refute this action? (y/n)" << endl;
					char ans2;
					cin >> ans2;
					if (ans == 'y') {
						cout << "Which player claims to have the duke?" << endl;
						int playNum;
						cin >> playNum;
						if (players.at(playNum)->getCardOne()->getDefense() == "Block Foreign Aid" || players.at(playNum)->getCardTwo()->getDefense() == "Block Foreign Aid") {
							cout << players.at(turn)->getName() << ", the other player has the Duke. You lose a card." << endl;
							players.at(turn)->loseCard();
						}
						else {
							cout << players.at(playNum)->getName() << ", the other player has called your bluff correctly. You lose a card." << endl;
							players.at(playNum)->loseCard();
						}

					}
					else {
						cout << players.at(turn)->getName() << " does not take Foreign Aid. Nothing happens." << endl;
					}
				}
				else {
					cout << players.at(turn)->getName() << " takes Foreign Aid. 2 coins are added to their purse." << endl;
					players.at(turn)->addCoin();
					players.at(turn)->addCoin();
				}
				break;
				//Duke Tax
			case 4:
				cout << players.at(turn)->getName() << "is trying to take the Duke Tax. Does any person want to block this? (y/n)" << endl;
				char ans2;
				cin >> ans2;
				//Block
				if (ans == 'y') {
					cout << "Current Player: Would you like to refute this action? (y/n)" << endl;
					char ans2;
					cin >> ans2;
					//Refute
					if (ans == 'y') {
						cout << "Which player claims that the other person does not have the duke? " << endl;
						int playNum;
						cin >> playNum;

						//Looks for duke
						if (players.at(turn)->getCardOne()->getDefense() == "Block Foreign Aid" || players.at(turn)->getCardTwo()->getDefense() == "Block Foreign Aid") {
							cout << players.at(playNum)->getName() << ", the other player has the Duke. You lose a card." << endl;
							players.at(playNum)->loseCard();
						}
						else {
							cout << players.at(turn)->getName() << ", the other player has called your bluff correctly. You lose a card." << endl;
							players.at(turn)->loseCard();
						}

					}
					else {
						cout << players.at(turn)->getName() << " does not take Foreign Aid. Nothing happens." << endl;
					}
				}
				//The duke tax goes through
				else {
					cout << players.at(turn)->getName() << " takes the Duke Tax. 3 coins are added to their purse." << endl;
					players.at(turn)->addCoin();
					players.at(turn)->addCoin();
					players.at(turn)->addCoin();
				}
				break;
				//COUP
			case 3:
				cout << players.at(turn)->getName() << " is going to coup someone, who are they going to choose?" << endl;
				int ans3;
				cin >> ans3;
				players.at(ans3)->loseCard();
				if (players.at(ans3)->isDead()) {
					cout << "I'm sorry " << players.at(ans3)->getName() << ", you are dead." << endl;
				}
				break;
				//Assassinate ToDO: call bs on if they have an assassin
			case 5:
			{
				int playerNumber = -1;
				do {
					string nameOfPlayer;
					cout << players.at(turn)->getName() << " who would you like to assassinate?" << endl;
					cin >> nameOfPlayer;
					//Looks for the player
					for (int i = 0; i < int(players.size()); i++) {
						if (nameOfPlayer == players.at(i)->getName()) {
							playerNumber = i;
						}
					}

				} while (playerNumber == -1);

				cout << players.at(playerNumber)->getName() << " do you block with your Contessa?" << endl;
				char contess;
				cin >> contess;
				//Block
				if (contess == 'y') {
					cout << players.at(turn)->getName() << ", do you belive that the other player has a contessa? (y/n)" << endl;
					char ans2;
					cin >> ans2;
					//Refute
					if (ans == 'n') {
						//Looks for contessa
						if (players.at(playerNumber)->getCardOne()->getDefense() == "Block Assassination" || players.at(playerNumber)->getCardTwo()->getDefense() == "Block Assassination") {
							cout << players.at(playerNumber)->getName() << "has the Contessa." << players.at(turn)->getName() << ", you lose a card." << endl;
							players.at(turn)->loseCard();
						}
						else {
							cout << players.at(turn)->getName() << ", the other player has bluffed. You assassinate them." << endl;
							players.at(playerNumber)->loseCard();
						}

					}
					//Does think the other player has the Contessa
					else {
						cout << players.at(turn)->getName() << " does not sucessfully assassiante. He loses 3 coins in his attempt to assassiante." << endl;
					}
				}
				//The duke tax goes through
				else {

					cout << players.at(turn)->getName() << " assassinates " << players.at(playerNumber)->getName() << endl;
					players.at(playerNumber)->loseCard();
				}
			}//end of case 5
				break;

				//Exchange
			case 6:
			{
				cout << players.at(turn)->getName() << "is trying to take the exchange their card. Does any person want to refute this? (y/n)" << endl;
				char refute;
				cin >> refute;
				//Block
				if (refute == 'y') {
					cout << "Which player claims that the other person does not have the Ambassador? " << endl;
					for (int i = 0; i < int(players.size()); i++) {
						cout << i << ". " << players.at(i)->getName() << endl;
					}
					int playNum;
					cin >> playNum;

					//Looks for Ambassador
					if (players.at(turn)->getCardOne()->getAttack() == "Exchange" || players.at(turn)->getCardTwo()->getAttack() == "Exchange") {
						cout << players.at(playNum)->getName() << ", the other player has the Ambassador. You lose a card." << endl;
						players.at(playNum)->loseCard();
					}
					else {
						cout << players.at(turn)->getName() << ", the other player has called your bluff correctly. You lose a card." << endl;
						players.at(turn)->loseCard();
					}
				}
				//The exchange works
				else {
					cout << players.at(turn)->getName() << " exchanges cards " << endl;
					int randNum1, randNum2;
					randNum1 = rand() % 15;
					randNum2 = rand() % 15;
					while (randNum1 == randNum2) {
						randNum2 = rand() % 15;
					}
					cout << deck.at(randNum1)->getArt();
					cout << deck.at(randNum2)->getArt();
				}
			}//end of clase 6
				break;

			//stealing
			case 7:


			}//end of switch



		}//end of turn

		turn++;
	}//end of while loop



	return 0;
} //end of main


std::string getFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}