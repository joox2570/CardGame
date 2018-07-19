#include "Cards.h"

Card::Card(char suit, short int num) {
	cardSuit = suit;
	cardNum = num;
}

std::deque<Card> createDeck() {
	std::deque<Card> deck;
	for (int s = Spade; s < 4; s++) {
		char suit;
		switch (s) {
		case Spade:
			suit = 'S';
			break;
		case Heart:
			suit = 'H';
			break;
		case Club:
			suit = 'C';
			break;
		case Diamond:
			suit = 'D';
			break;
		}
		for (short int i = 1; i < 14; i++) {
			deck.push_back(Card(suit, i));
		}
	}
	return deck;
}

void shuffle(std::deque<Card> &deck) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(std::begin(deck), std::end(deck), std::default_random_engine(seed));
}

std::ostream& operator<<(std::ostream& os, Card c) {
	os << c.cardSuit << c.cardNum;
	return os;
}