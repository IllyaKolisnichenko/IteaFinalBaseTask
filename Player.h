#pragma once
#include <iostream>
#include <string>
#include "FishGear.h"

class player {
public:
    void setPlayerName() {
        std::cout << "Please enter your name: ";
        std::cin >> name;
    }

    std::string getPlayerName() {
        return name;
    }

    void setNumberOfFish(int fish) {
        numberOfFish += fish;
    }

    int getNumberOfFish() {
        return numberOfFish;
    }

    void addMoney(int currentMoney) {
        money += currentMoney;
    }

    void subMoney(int currentMoney) {
        money -= currentMoney;
    }

    int getMoney() {
        return money;
    }

    bool pullFish(fishingGear* fishingGear) {
        return fishingGear->pullFish();
    }
private:
    const int startMoney{ 100 };
    std::string name;
    int numberOfFish{};
    int totalOfFish{};
    int money{ startMoney };
};
