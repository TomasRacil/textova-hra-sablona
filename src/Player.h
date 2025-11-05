#pragma once
#include <string>
#include <vector>
#include "Location.h"
#include "Item.h"

class Player {
public:
    /**
     * @brief Konstruktor hráče.
     * @param startLocation Ukazatel na místnost, kde hráč začíná.
     */
    Player(Location* startLocation);

    /**
     * @brief Vypíše popis aktuální místnosti.
     */
    void look() const;

    /**
     * @brief Pokusí se přemístit hráče do jiné místnosti.
     * @param direction Směr, kterým se má jít (např. "sever").
     */
    void move(const std::string& direction);

    // TODO: Můžete doplnit inventář a metody pro interakci atd.
    // void take(const std::string& itemName);
    // void drop(const std::string& itemName);
    // void showInventory() const;

private:
    Location* currentLocation;
    // std::vector<Item*> inventory;
};