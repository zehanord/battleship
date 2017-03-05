void check(int *x, int min, int max) {
	while(true) {
		char c = 0;
		cout << ">> ";
		cin >> *x;
		if (*x >= min && *x <= max) break;
		cout << "Not a valid option. Please try again." << endl;
	}
}

class ship {
private:
	int size;
	int health;
	ship *next;
public:
	ship(int a) {
		size = health = a;
		next = NULL;
	}
	~ship() {}
	void setSize(int newSize) { size = newSize; }
	int getSize() { return size; }
	void setHealth(int newHealth) { health = newHealth; }
	int getHealth() { return health; }
	void setNext(ship *nextShip) { next = nextShip; }
	ship *getNext() { return next; }
};

class player {
private:
	string name;
	int score;
	ship *shipList;
public:
	player(string newName, int ships, int *shipSizes) {
		name = newName;
		score = ships;
		shipList = NULL;
		for(int i = 0; i < ships; i++) {
			ship *temp = new ship(shipSizes[i]);
			if(!temp) {
				cout << "Sorry, out of memory... Please try again later." << endl << "Battleship terminated." << endl;
				exit(2);
			}
			this->insert(temp);
		}
//		printShipList();
	}
	~player() {}
	void setName(string newName) { name = newName; }
	void setScore(int newScore) { score = newScore; }
	string getName() { return name; }
	int getScore() { return score; }
	ship *getShipList() { return shipList; }
	void insert(ship *aShip) {
		if (shipList == NULL) shipList = aShip;
		else {
			ship *checker = shipList;
			while(checker->getNext() != NULL) checker = checker->getNext();
			checker->setNext(aShip);
		}
	}
//	void printShipList() {
//		cout << "I have these ships:" << endl;
//		ship *checker = shipList;
//		while(checker != NULL) {
//			cout << "--> A ship with size " << checker->getSize() << endl;
//			checker = checker->getNext();
//		}
//	}
};
