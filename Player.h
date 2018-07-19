#pragma once
#include <list>
#include <string>
#include <iostream>
#include "Person.h"
#include "Cards.h"

class Player : public Person {
	int chips;
	std::list<Card> hand;
public:
	Player();
	Player(std::string);
	Player(std::string, int);
	int chipCount() const;
	void showHand() const;
	void showHand(char) const;
	int score() const;
	Player& operator<<(Card);
	Player& operator+=(int);
	Player& operator-=(int);
};

Player createPlayer();