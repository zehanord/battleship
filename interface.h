class interface {
private:
	bool realOpponent;
	int ships;
public:
	interface() {
		int opponent = ships = 0;
		string name;
		cout << " ********** WELCOME TO TERMINAL BATTLESHIP ********** " << endl << endl;
		cout << "Will you play against (enter 1 or 2):" << endl << "(1) A real person?" << endl << "(2) The computer?" << endl;
		cout << "(BETA version note: only person vs. computer supported)" << endl;
		check(&opponent, 1, 2);
		if (opponent == 1) this->setOpponent(true);
		else this->setOpponent(false);
		cout << endl << "What is your name, commander?" << endl;
		cin.ignore(1);
		getline(cin, name);
		cout << endl << "How many ships do you want each player to command? (Enter a number between 1 and 5)" << endl;
		check(&ships, 1, 5);
		int shipSizes[ships];
		cout << endl << "Enter (one by one) the strengths of each ship for each player (a number between 2 and 5):" << endl;
		for(int i = 0; i < ships; i++) check(&shipSizes[i], 2, 5);
		this->setShips(ships);
		player gamer(name, ships, shipSizes);
		graphics gui(&gamer, ships);
		
	}
	~interface() {}
	void setOpponent(bool opponent) { realOpponent = opponent; }
	void setShips(int newShips) { ships = newShips; }
	bool getOpponent() { return realOpponent; }
	int getShips() { return ships; }
};