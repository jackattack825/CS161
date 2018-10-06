// TODO : have 5 endings, 3 so far

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int size_places = 10;
const int size_enemies = 15;


const string places[size_places] = {"Dungeon", "Dragonsreach", "Mount Anthor", "Ancient's Ascent", "Druadach Redoubt", "Dushnikh Yal", "Broken Limb Camp", "Anga's Mill", "Bloodlet Throne", "Abandoned Shack"};
const string enemies[size_enemies] = { "Draugr", "Elder Dragon", "Dragon Priest", "Troll", "Frost Spider", "Giant", "Flame Atronach",
							"Forsworn", "Bandit", "Falmer", "Dark Elf", "Wood Elf", "Necromancer", "Ritual Master", "Mage" };
const int probAttack = 55;
const int probRun = 75;
const int probDeath = 5;

const int winScoreLow = 5;
const int winScoreMed = 10;
const int winScoreHig = 15;

struct Player {
	int lives;
	int points;
};

Player p;


Player promptUser(Player pl) {
	int num;
//	srand(time(NULL));
	//int ranLoc = (rand() % sizeof(size_places)); //gets random index from places array
	int ranLoc = (rand() % size_places);
//	cout << "ranLoc is " << ranLoc << endl;//debugging
	int ranLoc2 = ranLoc;
	while (ranLoc2 == ranLoc) {
//		srand(time(NULL));
		//ranLoc2= (rand() % sizeof(size_places)); //gets random index from places array not already used
		ranLoc2 = (rand() % size_places);
	}
//	cout << "ranLoc2 is " << ranLoc2 << endl;//debugging
//	srand(time(NULL));
	//int ranEne = (rand() % sizeof(size_enemies)); //gets random index from enemies array
	int ranEne = (rand() % size_enemies);

	cout << "Would you like to go to " << places[ranLoc] << " \nor " << places[ranLoc2] << endl;
	cout << "0 for the first and 1 for the second" << endl;
	cout << endl;
	cin >> num;
	cout << endl;

	while ((num != 0) && (num != 1)) { //weed out improper inputs
		cout << " You have chosen an invalid input, please try again" << endl;
		cout << "Would you like to go to " << places[ranLoc] << " \nor " << places[ranLoc2] << endl;
		cout << "0 for the first and 1 for the second" << endl;
		cout << endl;
		cin >> num;
		cout << endl;
	}
	if (num == 0) {
		cout << "You have chosen to go to " << places[ranLoc] << endl;
		cout << endl;
	}
	else {
		cout << "You have chosen to go to " << places[ranLoc2] << endl;
		cout << endl;
	}
	cout << "Oh no a " << enemies[ranEne] << " has appeared! \nType 0 to attack or 1 to run" << endl;
	cout << endl;
	int choice;
	cin >> choice;
	cout << endl;
	while ((choice != 0) && (choice != 1)) { //weed out improper inputs
		cout << " You have chosen an invalid input, please try again" << endl;
		cout << "Oh no a " << enemies[ranEne] << " has appeared!\nType 0 to attack or 1 to run" << endl;
		cout << endl;
		cin >> choice;
		cout << endl;
	}
	
		int deathProb = rand() % 100;
		if (deathProb <= probDeath) {
			pl.lives = 0;
			cout << "You are very unlucky and died from fright. \nBetter luck next time" << endl;
			return pl;
		}

	if (choice == 0) {
//		srand(time(NULL));
		int num = rand() % 100 + 1;
		if (num <= probAttack) {
			cout << "Successfully hit the " << enemies[ranEne] << endl;
			cout << endl;
			pl.points += 2;
			cout << "You have " << pl.points << " points" << endl;
			return pl; //something goes here
		}
		else {
			cout << "Oops you missed and they didn't. You have lost a life" << endl;
			cout << endl;
			pl.lives--;
			cout << pl.lives << " lives remaining" << endl;
			return pl; //something goes here
		}

	}
	
	else { // choice has to equal 1 here
//		   srand(time(NULL));
		int num = rand() % 100 + 1;
		if (num <= probRun) {
			cout << "Successfully ran from the " << enemies[ranEne] << endl;
			cout << endl;
			pl.points++;
			cout << "You have " << pl.points << " points" << endl;
			return pl; //something goes here
		}
		else {
			cout << "Oops you tripped and they hit you. You have lost a life" << endl;
			cout << endl;
			pl.lives--;
			cout << pl.lives << " lives remaining" << endl;
			return pl; //something goes here
		}
	}

	

	
}

void ClearScreen() {

	cout << string(100, '\n');
}

void runGame() {
	p.points = 0; //points
	p.lives = 3; //lives
	cout << "You will have 3 lives. Every round you will choose between two locations and encounter an enemy." << endl;
	cout << "Next you will choose whether to attack or run away. Each decision has a chance of success. If unsuccessful you escape the encounter while losing a life. " << endl;
	cout << "If successfully attacking, you will earn two points, and if running one point." << endl;
	cout << endl;
	cout << "Good luck!" << endl;
	
	do {
		p = promptUser(p);
		cout << endl;
		cout << "new round\n";
	} while (p.lives > 0);

	cout << "Game over. You scored " << p.points << " points" << endl;
	cout << endl;
	if (p.points >= winScoreHig)
		cout << "You are a pro, keep working harder" << endl;
	else if ((p.points < winScoreHig) && (p.points >= winScoreMed))
		cout << "You are decent, improve that score" << endl;
	else if ((p.points < winScoreMed) && (p.points >= winScoreLow))
		cout << "You are pretty bad, these are rooky numbers" << endl;
	else 
		cout << "You are complete trash, uninstall this game and find a true meaning to your life" << endl;
	cout << "Type 1 to play again" << endl;
	int ans;
	cin >> ans;
	cout << endl;

	if (ans == 1) {
		ClearScreen();
		runGame();
	}

}




int main() {
	srand(time(NULL));
	char ans;
	cout << "Welcome to the Elder Scrolls Text Edition. Press 1 to play or 0 if you are lame" << endl;
	cin >> ans;
	cout << endl;

	if (ans == '1')
		runGame();


	return 0;
}


