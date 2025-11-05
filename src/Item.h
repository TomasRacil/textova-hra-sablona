#pragma once
#include <string>

class Item {
public:
    std::string name;
    std::string description;

    Item(std::string name, std::string description);
    
    // TODO: Můžete přidat virtuální metody, např.
    // virtual void use(Player* player);
};