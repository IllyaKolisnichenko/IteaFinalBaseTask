#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "Fish.h"
#include "Bait.h"
#include "Water.h"


class Game {
private:
    River& river_;
    Lake& lake_;
    Reservoir& reservoir_;

    Crucian& crucian_;
    Perch& perch_;
    Pike& pike_;

    Bait& bloodworm_;
    Bait& earthworm_;
    Bait& maggot_;

    int totalFishWeight_ {};
    int paidFishWeight_ {};
    int fishingTime_ {};
    std::string nameWater_ {};
    int catchingFishChance_ {};
    std::string nameBait_ {};
    int catchBonus_ {};
    std::vector <std::pair <int, std::string>> currentCatch_;

private:
    void paidTime();

    void chooseFish( int& currentFishWeight, std::string& currentFishName, bool& baitPreferenses );

public:
    Game( River& river, Lake& lake, Reservoir& reservoir, Crucian& crucian, Perch& perch, Pike& pike, Bait& bloodworm, Bait& earthworm, Bait& maggot );

    int getPaidFishWeight();
    int getCurrentFishWeight();
    int getCurrentFishingTime();
    void checkCurrentCatch();
    std::vector <std::pair <int, std::string>> getCurrentCatch();
    void chooseWater();
    void chooseBait();
    void catching();
};
