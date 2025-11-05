#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Location.h"

class Game {
public:
    Game();
    ~Game(); // Destruktor pro uvolnění paměti

    /**
     * @brief Spustí hlavní herní smyčku.
     */
    void run();

private:
    /**
     * @brief Inicializuje herní svět (místnosti, předměty).
     */
    void setupWorld();

    /**
     * @brief Zpracuje příkaz zadaný hráčem.
     * @param input Příkaz od hráče.
     */
    void processCommand(const std::string& input);

    Player* player;
    bool gameRunning;

    // Seznam všech místností pro snadné uvolnění paměti
    std::vector<Location*> allLocations; 
};