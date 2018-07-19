#pragma once
#include <iostream>
#include <deque>
#include <algorithm>
#include <random>
#include <chrono>

enum Suit {Spade, Heart, Club, Diamond};

struct Card {
	short int cardNum;
	char cardSuit;
	Card(char, short int);
};

std::deque<Card> createDeck();
//std::deque<Card> createDeck(int);
void shuffle(std::deque<Card>&);
std::ostream& operator<<(std::ostream&, Card);