#pragma once

#include <fstream>
#include <string>
#include <vector>

// Controls the game board for Hangman
class Board {
private:

	// The different difficulties for the game
	enum class Difficulty : uint8_t {
		Easy,
		Medium,
		Hard,
		Extreme
	};

	std::string board;
	std::string alphabet;
	std::string solution;
	std::string answer;
	std::vector<bool> usedLetters;
	size_t fails;
	Difficulty choice;

public:

	// Default contructor
	// Asks use for difficulty choice, then loads a random word from the respective text files
	Board() : fails{ 0 },
	board{ "     +-----+\n     |     |\n     |      \n     |       \n     |       \n     |\n=======================\n\n" },
	alphabet{ "\x1b[4ma\x1b[0m \x1b[4mb\x1b[0m \x1b[4mc\x1b[0m \x1b[4md\x1b[0m \x1b[4me\x1b[0m \x1b[4mf\x1b[0m \x1b[4mg\x1b[0m \x1b[4mh\x1b[0m \x1b[4mi\x1b[0m \x1b[4mj\x1b[0m \x1b[4mk\x1b[0m \x1b[4ml\x1b[0m \x1b[4mm\x1b[0m \x1b[4mn\x1b[0m \x1b[4mo\x1b[0m \x1b[4mp\x1b[0m \x1b[4mq\x1b[0m \x1b[4mr\x1b[0m \x1b[4ms\x1b[0m \x1b[4mt\x1b[0m \x1b[4mu\x1b[0m \x1b[4mv\x1b[0m \x1b[4mw\x1b[0m \x1b[4mx\x1b[0m \x1b[4my\x1b[0m \x1b[4mz\x1b[0m\n\n" } {
		usedLetters.resize(26, false);
	}

};

