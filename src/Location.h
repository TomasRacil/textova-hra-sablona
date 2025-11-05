#pragma once
#include <string>
#include <map>
#include <vector>
#include "Item.h" // Bude potřeba pro předměty v místnosti

// Předběžná deklarace (forward declaration), abychom předešli cyklické závislosti
// Protože Location potřebuje znát Item a Item (možná) potřebuje znát Location.
class Item; 

class Location {
public:
    std::string name;
    std::string description;
    
    // Propojení místností. Klíč je směr (napr. "sever"), hodnota je ukazatel na místnost.
    std::map<std::string, Location*> exits;

    // Předměty v místnosti
    std::vector<Item*> items;

    /**
     * @brief Konstruktor pro vytvoření nové lokace.
     * @param name Krátký název místnosti (např. "Temná jeskyně").
     * @param description Delší popis, který se hráči zobrazí.
     */
    Location(std::string name, std::string description);

    /**
     * @brief Vypíše plný popis místnosti, včetně východů a předmětů.
     */
    void describe() const;

    /**
     * @brief Přidá východ z této místnosti do jiné.
     * @param direction Název směru (např. "sever", "vychod", "dolu").
     * @param target Ukazatel na cílovou místnost.
     */
    void addExit(const std::string& direction, Location* target);

    /**
     * @brief Vrátí ukazatel na místnost v daném směru.
     * @param direction Směr, kterým se hráč chce vydat.
     * @return Ukazatel na cílovou místnost, nebo nullptr, pokud tam není východ.
     */
    Location* getExit(const std::string& direction);

    // TODO: Doplnit metody pro přidávání/odebírání předmětů
    // void addItem(Item* item);
    // Item* takeItem(const std::string& itemName);
};