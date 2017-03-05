class graphics {
private:
	int playerShips;
public:
	graphics(player *gamer, int ships) {
		playerShips = ships;
		system("clear");
		cout << "    A  B  C  D  E  F  G  H  I  J" << endl;
		for(int i = 0; i < 10; i++) {
			cout << " " << i << " ";
			for(int j = 0; j < 10; j++) cout <<" ~ ";
			cout << endl;
		}
		for(int i = 0; i < 33; i++) cout << "=";
		cout << endl;
		for(int i = 9; i >= 0; i--) {
			cout << " " << i << " ";
			for(int j = 0; j < 10; j++) cout <<" ~ ";
			cout << endl;
		}
		cout << "    A  B  C  D  E  F  G  H  I  J" << endl;
		for (int i = 0; i < 4; i++) cout << endl;
		setup(gamer, ships);
	}
	~graphics() {}
	void setPlayerShips(int ships) { playerShips = ships; }
	int getPlayerShips() { return playerShips; }
	void setup(player *gamer, int ships) {
		ship *builder = gamer->getShipList();
		int counter = 1;
		string spot = "w";
		string direction = "w";
		while(builder != NULL) {
			spot = "w";
			cout << "Name a spot to put the poop of your ship no" << counter << "on : ";
			while(true) {
				cin.ignore(1);
				cin >> spot;
				if (spot.length() == 2 && spot[0] >= 'A' && spot[0] <= 'J' && spot[1] >= '0' && spot[1] <= '9') break;
				else cout << "Not a valid spot. Try again." << endl << ">> ";
			}
				cout << "Where do you want your ship to face? (u, r, l, d): ";
			while(true) {
				cin.ignore(1);
				cin >> direction;
				if (direction == "u" || direction == "r" || direction == "l" || direction == "d") break;
				else cout << "Not a valid direction. Try again." << endl << ">> ";	
			}
			// ship positioning
		}
	}
	void rewriteSpot() {}
	void rewriteRow() {}
	void rewriteColumn() {}
};
