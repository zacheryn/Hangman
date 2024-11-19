#include "ansi_escapes.h"
#include "Audio.h"
#include <iostream>


int main() {
    setupConsole();

    std::cout << "\x1b[1;4mHello\x1b[0m \x1b[4mWorld!\x1b[0m\n";
    std::cout << "     +-----+\n     |     |\n     |      \n     |       \n     |       \n     |\n=======================\n\nAlphabet:\n"
              << "\x1b[4ma\x1b[0m \x1b[4mb\x1b[0m \x1b[4mc\x1b[0m \x1b[4md\x1b[0m \x1b[4me\x1b[0m \x1b[4mf\x1b[0m \x1b[4mg\x1b[0m \x1b[4mh\x1b[0m \x1b[4mi\x1b[0m \x1b[4mj\x1b[0m \x1b[4mk\x1b[0m \x1b[4ml\x1b[0m \x1b[4mm\x1b[0m \x1b[4mn\x1b[0m \x1b[4mo\x1b[0m \x1b[4mp\x1b[0m \x1b[4mq\x1b[0m \x1b[4mr\x1b[0m \x1b[4ms\x1b[0m \x1b[4mt\x1b[0m \x1b[4mu\x1b[0m \x1b[4mv\x1b[0m \x1b[4mw\x1b[0m \x1b[4mx\x1b[0m \x1b[4my\x1b[0m \x1b[4mz\x1b[0m\n\n"
              << "Word:\n---f--\n\n";

    restoreConsole();
}
