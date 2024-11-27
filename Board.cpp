#include "Board.h"
#include <random>


Board::Difficulty Board::choose_diff() {
	std::string input;

	while (input != "1" && input != "2" && input != "3" && input != "4") {
		std::cout << "Please choose a difficulty (enter a number):\n\n"
			<< "\t1. Easy (3 - 5 Letters)\n"
			<< "\t2. Medium (6 - 8 Letters)\n"
			<< "\t3. Hard (9 - 11 Letters)\n"
			<< "\t4. Extreme (12+ Letters)\n\n";

		std::cin >> input;
	}

	if (input == "1") {
		return Difficulty::Easy;
	}
	else if (input == "2") {
		return Difficulty::Medium;
	}
	else if (input == "3") {
		return Difficulty::Hard;
	}

	return Difficulty::Extreme;
}


void Board::grab_solution(const std::string fname) {
	std::ifstream fin(fname);

	// Check to make sure the given file was opened
	if (!fin.is_open()) {
		std::cerr << "Error: Could not open file '" << fname << "'\n"
			<< "Please make sure the exe is in the same directory as '" << fname
			<< '\'' << std::endl;
		exit(1);
	}

	// Set up the rng to grab a random word
	std::mt19937_64 rng(time(NULL));
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	// Loop through the given file one word at time while maintaining equal probablility
	double i = 1;
	std::string input;
	while (fin >> input) {
		if (dist(rng) < (1.0 / i)) {
			solution = input;
		}
		++i;
	}
}


void Board::add_fail() {
	switch (fails) {
	case 0:
		// Add head
		board[37] = 'O';
		break;
	case 1:
		// Add torso
		board[50] = '|';
		break;
	case 2:
		// Add left arm
		board[49] = '/';
		break;
	case 3:
		// Add right arm
		board[51] = '\\';
		break;
	case 4:
		// Add left leg
		board[63] = '/';
		break;
	default:
		//Add right leg
		board[65] = '\\';
		break;
	}

	++fails;

	if (sounds != nullptr)
		sounds->Play("wrong.wav", 0.10f, false);
}


void Board::print_setup() {
	std::cout << board;
	for (const auto& s : alphabet) {
		std::cout << s << ' ';
	}
	std::cout << "\n\nWord:\n" << answer << "\n\n";
}


void Board::check_letter(const char letter) {
	bool correct = false;
	for (size_t i = 0; i < solution.length(); ++i) {
		if (solution[i] == letter) {
			answer[i] = letter;
			++successes;
			correct = true;
		}
	}

	usedLetters[letter - 'a'] = true;
	std::string temp("");
	if (correct) {
		temp += "\x1b[4;32m";
		if (sounds != nullptr)
			sounds->Play("correct.wav", 1, false);
	}
	else {
		temp += "\x1b[4;31m";
		add_fail();
	}
	temp += letter;
	temp += "\x1b[0m";

	alphabet[letter - 'a'] = temp;
}


void Board::play() {
	std::string input("");

	while (true) {
		print_setup();
		std::cout << "Please enter a letter: " << std::flush;

		std::cin >> input;
		if (input.length() > 1) {
			std::cout << "\x1b[1mPlease only enter a single letter.\x1b[0m\n" << std::endl;
			continue;
		}
		else if ((input[0] - 'a') < 0 || (input[0] - 'a') > 25) {
			std::cout << "\x1b[1mPlease only use lowercase letters (a-z).\x1b[0m\n" << std::endl;
			continue;
		}
		else if (usedLetters[input[0] - 'a']) {
			std::cout << "\x1b[1mYou have already entered that letter. Try again.\x1b[0m\n" << std::endl;
			continue;
		}

		check_letter(input[0]);

		if (fails >= 6) {
			print_setup();

			std::cout << "The correct answer was '" << solution << "'\n";
			std::cout << "Better luck next time!\n" << std::endl;
			break;
		}
		if (successes >= solution.length()) {
			print_setup();

			std::cout << "Congratulations, you won!\n" << std::endl;
			break;
		}
	}
}

void Board::startSoundEngine(const std::string path) {
	sounds = new Audio(path);
}
