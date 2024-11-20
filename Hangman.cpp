#include "ansi_escapes.h"
#include "Audio.h"
#include "Board.h"
#include <iostream>


int main() {
    // Makes sure that I can use ANSI Escape codes
    setupConsole();

    Board board;

    // Resets console to its default state if changes were made for ANSI Escape codes
    restoreConsole();
}
