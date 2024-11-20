#pragma once

#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include <iostream>
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
	std::vector<std::string> alphabet;
	std::string solution;
	std::string answer;
	std::vector<bool> usedLetters;
	size_t fails;
	Difficulty choice;

	// Asks user to give difficulty
	Difficulty choose_diff();

	// Pulls a random word for the given file name
	void grab_solution(std::string);

	// Adds the next body piece on fail
	void add_fail();

public:

	// Default contructor
	// Asks use for difficulty choice, then loads a random word from the respective text files
	Board() : fails{ 0 },
	board{ "     +-----+\n     |     |\n     |      \n     |       \n     |       \n     |\n=======================\n\n" },
	answer{ "" } {
		usedLetters.resize(26, false);
		for (int i = 0; i < 26; ++i) {
			std::string temp("\x1b[4m");
			temp += ('a' + i);
			temp += "\x1b[0m";
			alphabet.push_back(temp);
		}

		choice = choose_diff();
		switch (choice) {
		case Difficulty::Easy:
			grab_solution("easy.txt");
			break;
		case Difficulty::Medium:
			grab_solution("medium.txt");
			break;
		case Difficulty::Hard:
			grab_solution("hard.txt");
			break;
		case Difficulty::Extreme:
			grab_solution("extreme.txt");
			break;
		}
	}

};

#endif
