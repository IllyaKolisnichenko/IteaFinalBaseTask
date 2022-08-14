#pragma once
#include <iostream>
#include <fstream>
#include <string>

class fish {
private:
    int minWeight{};
    int maxWeight{};
    int priñeOfFish{};
    int totalFishWeight{};
    std::string path = "Fish.txt";
public:
    void getFishInfo(std::string fishName) {
        std::ifstream fishFile;
        fishFile.open (path);

        if (!fishFile.is_open())
        {
            std::cout << "Can't open file with fish data" << std::endl;
        }

        while (!fishFile.eof())
        {
            std::string str;
            fishFile >> str;
            if (str == fishName)
            {
                fishFile >> str;
                minWeight = stoi(str);
                fishFile >> str;
                maxWeight = stoi(str);
                fishFile >> str;
                priñeOfFish = stoi(str);
                break;
            }
        }
        fishFile.close();
    }

    int getFishWeight()
    {
        std::srand(time(nullptr));
        int fishWeight = minWeight + std::rand() % (maxWeight - minWeight);
        totalFishWeight += fishWeight;
        return fishWeight;
    }
    int getPriceOfFish() {
        return priñeOfFish;
    }
    int getTotalFishWeight() {
        return totalFishWeight;
    }
};

