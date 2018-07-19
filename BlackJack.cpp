#include "Player.h"
#include "Cards.h"
#include "Person.h"
#include <iostream>
#include <string>

int main() {
	std::cout << "See Plus Plus Games!" << std::endl;
	int chips = 0;
	bool cont = true;
	int gameNum = 0;
	Player player_one = createPlayer();
	while (cont == true && player_one.chipCount() > 0) {
		gameNum++;
		std::cout << "Game Number " << gameNum << std::endl;
		do {
			std::cout << "Make a bet: ";
			std::cin >> chips;
			if (chips > player_one.chipCount()) {
				std::cout << "You can't bet more than what you have!" << std::endl;
			}
		} while (chips > player_one.chipCount());
		if (chips > 0) {
			player_one -= chips;
			char ans;
			Player dealer("Dealer");
			auto deck = createDeck();
			shuffle(deck);
			player_one << deck.front();
			deck.pop_front();
			dealer << deck.front();
			deck.pop_front();
			player_one << deck.front();
			deck.pop_front();
			dealer << deck.front();
			deck.pop_front();
			std::cout << "Your Hand: ";
			player_one.showHand();
			std::cout << "Dealer's Hand: ";
			dealer.showHand('D');
			std::cout << "Hit or Stay? (H or S) ";
			std::cin >> ans;
			while (ans == 'H' || ans == 'h') {
				player_one << deck.front();
				deck.pop_front();
				player_one.showHand();
				std::cout << "Hit or Stay? (H or S) ";
				std::cin >> ans;
			}
			std::cout << "Now Dealer Plays..." << std::endl;
			while (dealer.score() != 0 && dealer.score() < 17) {
				dealer << deck.front();
				deck.pop_front();
			}
			std::cout << "Dealer's Hand: ";
			dealer.showHand();
			if (player_one.score() > dealer.score()) {
				std::cout << "You Win!" << std::endl;
				player_one += (chips * 2);
			}
			else if (player_one.score() == 0 || player_one.score() < dealer.score()) {
				std::cout << "You Lose!" << std::endl;
			}
			else {
				std::cout << "Draw!" << std::endl;
				player_one += chips;
			}
		}
	}
}