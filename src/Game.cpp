#include "Game.h"
#include <iostream>
#include <sstream>

Game::Game() : player(nullptr), gameRunning(true) {
    setupWorld();
}

Game::~Game() {
    // Uvolníme paměť po hráči
    delete player;

    // Uvolníme paměť po všech místnostech
    std::cout << "Uklízení světa..." << std::endl;
    for (Location* loc : allLocations) {
        delete loc;
    }
    std::cout << "Hotovo. Hra končí." << std::endl;
}

void Game::setupWorld() {
    std::cout << "Vytvářím svět..." << std::endl;

    // Vytvoření místností
    Location* forest = new Location("Lesní mýtina", "Jsi na mýtině uprostřed temného lesa. Cesta vede na sever.");
    Location* cave = new Location("Vstup do jeskyně", "Před tebou je temný vstup do jeskyně. Z jihu jsi přišel z lesa.");
    Location* darkRoom = new Location("Tmavá místnost", "Nevidíš skoro nic, ale slyšíš kapání vody. Východ je na jih.");

    // Uložíme si je pro pozdější smazání
    allLocations.push_back(forest);
    allLocations.push_back(cave);
    allLocations.push_back(darkRoom);

    // Propojení místností
    forest->addExit("sever", cave);
    cave->addExit("jih", forest);
    cave->addExit("sever", darkRoom);
    darkRoom->addExit("jih", cave);

    // Vytvoření hráče
    player = new Player(forest);

    std::cout << "Svět vytvořen." << std::endl;
}

void Game::run() {
    std::cout << "Vítej ve hře!" << std::endl;
    std::cout << "Tvůj úkol je... (doplňte příběh)" << std::endl;
    std::cout << "Pro nápovědu napiš 'help'." << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Úvodní popis
    player->look();

    std::string input;
    while (gameRunning) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            continue;
        }

        processCommand(input);
    }
}

void Game::processCommand(const std::string& input) {
    // Jednoduchý parser, který dělí vstup na příkaz a argument
    std::stringstream ss(input);
    std::string command;
    std::string argument;

    ss >> command; // První slovo je příkaz
    ss >> argument; // Druhé slovo je argument

    // Převod příkazu na malá písmena pro snadnější porovnání
    for (char &c : command) {
        c = tolower(c);
    }

    if (command == "konec" || command == "exit") {
        std::cout << "Děkujeme za hru. Nashledanou." << std::endl;
        gameRunning = false;
    } else if (command == "jdi" || command == "go") {
        if (argument.empty()) {
            std::cout << "Kam chceš jít? (např. 'jdi sever')" << std::endl;
        } else {
            player->move(argument);
        }
    } else if (command == "koukni" || command == "look") {
        player->look();
    } else if (command == "help") {
        std::cout << "Příkazy: " << std::endl;
        std::cout << "  jdi [sever|jih|vychod|zapad]" << std::endl;
        std::cout << "  koukni (prohlédneš si místnost)" << std::endl;
        std::cout << "  konec (ukončí hru)" << std::endl;
        // TODO: Doplňte další příkazy (vezmi, poloz, pouzij, inventar...)
    } else {
        std::cout << "Nerozumím příkazu '" << command << "'." << std::endl;
    }
}