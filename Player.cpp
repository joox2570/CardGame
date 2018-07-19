#include "Player.h"

Player::Player() : Person() {
	chips = 0;
	hand.clear();
}

Player::Player(std::string n) : Person(n) {
	chips = 0;
	hand.clear();
}

Player::Player(std::string n, int c) : Person(n) {
	chips = c;
	hand.clear();
}

int Player::chipCount() const {
	return chips;
}

void Player::showHand() const {
	for (std::list<Card>::const_iterator it = hand.begin(); it != hand.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void Player::showHand(char x) const {
	std::list<Card>::const_iterator it = --hand.end();
	std::cout << "X0 " << *it << std::endl;
}

int Player::score() const {
	int sum = 0;
	bool ace = false;
	for (std::list<Card>::const_iterator it = hand.begin(); it != hand.end(); it++) {
		if (it->cardNum >= 10)
			sum += 10;
		else if (it->cardNum == 1)
			ace = true;
		else
			sum += it->cardNum;
	}
	if (sum > 21)
		sum = 0;
	else if (sum <= 10 && ace == true)
		sum += 10;
	return sum;
}

Player& Player::operator<<(Card newCard) {
	hand.push_back(newCard);
	return *this;
}

Player& Player::operator+=(int c) {
	chips += c;
	return *this;
}

Player& Player::operator-=(int c) {
	chips -= c;
	return *this;
}

Player createPlayer() {
	std::string name;
	int chips = 0;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Number of chips: ";
	std::cin >> chips;
	Player player(name, chips);
	return player;
}