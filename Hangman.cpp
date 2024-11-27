#include "ansi_escapes.h"
#include "Board.h"
#include <conio.h>


int main(int argc, char* argv[]) {
    // Makes sure that I can use ANSI Escape codes
    setupConsole();

    // Get the path to the exe
    std::string path(argv[0]);

    // Get the directory the exe is in
    for (int i = path.length() - 1; i > 0; --i) {
        if (path[i] == '\\') break;
        else path.pop_back();
    }
    path += "Sounds\\";

    Board board;
    board.startSoundEngine(path);
    board.play();

    std::cout << "Press any key to continue..." << std::flush;
    _getch();

    // Resets console to its default state if changes were made for ANSI Escape codes
    restoreConsole();
}
