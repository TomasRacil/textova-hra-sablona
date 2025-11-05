#include "Player.h"
#include <iostream>

Player::Player(Location* startLocation) {
    this->currentLocation = startLocation;
}

void Player::look() const {
    currentLocation->describe();
}

void Player::move(const std::string& direction) {
    Location* nextLocation = currentLocation->getExit(direction);

    if (nextLocation != nullptr) {
        currentLocation = nextLocation;
        std::cout << "Přesunul jsi se." << std::endl;
        look();
    } else {
        std::cout << "Tímto směrem ('" << direction << "') jít nemůžeš." << std::endl;
    }
}