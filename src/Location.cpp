#include "Location.h"
#include <iostream>

Location::Location(std::string name, std::string description) {
    this->name = name;
    this->description = description;
    // Východy jsou na začátku prázdné
}

void Location::describe() const {
    // Vytiskne popis místnosti
    std::cout << "--- " << name << " ---" << std::endl;
    std::cout << description << std::endl;

    // Vypíše východy
    if (exits.empty()) {
        std::cout << "Nejsou tu žádné viditelné východy." << std::endl;
    } else {
        std::cout << "Můžeš jít: ";
        for (auto const& [direction, location] : exits) {
            std::cout << direction << " ";
        }
        std::cout << std::endl;
    }

    // TODO: Vypis předmětů v místnosti
    // ...
}

void Location::addExit(const std::string& direction, Location* target) {
    exits[direction] = target;
}

Location* Location::getExit(const std::string& direction) {
    // Zkusí najít východ v mapě
    if (exits.count(direction)) {
        return exits[direction];
    }
    return nullptr; // Nenalezeno
}