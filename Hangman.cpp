#include "ansi_escapes.h"
#include "Board.h"
#include <conio.h>


int main() {
    // Makes sure that I can use ANSI Escape codes
    setupConsole();

    Board board;
    board.play();

    std::cout << "Press any key to continue..." << std::flush;
    _getch();

    // Resets console to its default state if changes were made for ANSI Escape codes
    restoreConsole();
}
