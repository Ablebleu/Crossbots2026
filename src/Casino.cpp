#include "Casino.h"
#include <iostream>
#define CLEAR "\033[2J\033[1;1H"

Casino::Casino() : manager(), game(nullptr), player(nullptr) {
    player = new Player(); 
}

Casino::~Casino() {
    if (game) delete game;
    if (player) delete player;
}

void Casino::showLogo() const {
        std::cout << "_________                            __________        __          " << std::endl;
        std::cout << "\\_   ___ \\_______  ____  ______ _____\\______   \\ _____/  |_  ______" << std::endl;
        std::cout << "/    \\  \\/\\_  __ \\/  _ \\/  ___//  ___/|    |  _// __ \\   __\\/  ___/" << std::endl;
        std::cout << "\\     \\____|  | \\(  <_> )___ \\ \\___ \\ |    |   \\  ___/|  |  \\___ \\ " << std::endl;
        std::cout << " \\______  /|__|   \\____/____  >____  >|______  /\\___  >__| /____  >" << std::endl;
        std::cout << "        \\/                  \\/     \\/        \\/     \\/          \\/ " << std::endl;
        std::cout << "_______  ____  _____                                             " << std::endl;
        std::cout << "\\   _  \\/_   | /  |  |                                           " << std::endl;
        std::cout << "/  /_\\  \\|   |/   |  |_                                          " << std::endl;
        std::cout << "\\  \\_/   \\   /    ^   /                                          " << std::endl;
        std::cout << " \\_____  /___\\____   |                                           " << std::endl;
        std::cout << "        \\/        |__|                                           " << std::endl;
}

void Casino::run() {
    int option = -1;
    while(option!=0){
        std::cout << CLEAR;

        showLogo();
        std::cout << "Saldo do Jogador: $" << player->getMoney() << "\n\n";
        std::cout << "0 - Sair do Cassino\n";
        manager.showCatalog();

        std::cin >> option;

        if (option == 0) {
            std::cout << "Obrigado por jogar no CrossBets!\n";
            break;
        }

        if (option > 0) {
            if (game) {
                delete game;
                game = nullptr;
            }
            game = manager.getTable(option);
            if (game) {
                game->addPlayer(player);
                Games::TableAction action = Games::CONTINUE;
                while (action == Games::CONTINUE) {
                    action = game->play();
                }
                
                if (action == Games::EXIT_SESSION) {
                    std::cout << "Obrigado por jogar no CrossBets!\n";
                    break;
                }
            } 
        }
    }
}