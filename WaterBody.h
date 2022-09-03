#pragma once
#include <iostream>
#include <string>
#include <map>
#include <charconv>

class waterBody {
public:
    void setWaterFilePath(std::string path_) {
        path = path_;
    }
    std::string getWaterFilePath() {
        return path;
    }
    void createWaterBody(std::string waterType_) {
        std::ifstream waterFile;
        waterFile.open(path);

        if (!waterFile.is_open())
        {
            std::cout << "Can't open file with water data" << std::endl;
        }
        while (!waterFile.eof())
        {
            std::string str;
            waterFile >> str;
            if (str == waterType_)
            {
                waterFile >> str;
                rowDimension = stoi(str);
                waterFile >> str;
                colDimension = stoi(str);
                waterFile >> str;
                fish1 = str;
                waterFile >> str;
                fish2 = str;
                waterFile >> str;
                fish3 = str;
                waterFile >> str;
                fish4 = str;
                break;
            }
        }
        waterFile.close();

        for (int i{ 97 }; i < rowDimension + 97; i++) //create water body without fish; 97 is char "a" acording to ascii table
        {
            for (int j{ 0 }; j < colDimension; j++)
            {
                std::string mapKey;
                std::string row;
                row.push_back(static_cast<char>(i));
                std::string col = std::to_string(j);
                mapKey = row + col;
                waterMap.emplace(mapKey, 0);
            }
        }

        for (int i{ 97 }; i < rowDimension + 97; i++) //placement of fish in water body; 97 is char "a" acording to ascii table
        {
            for (int j{ 0 }; j < colDimension; j += rand() % 10)
            {
                std::string mapKey;
                std::string row;
                row.push_back(static_cast<char>(i)); ;
                std::string col = std::to_string(j);
                mapKey = row + col;
                waterMap[mapKey] = rand() % 5;
            }
        }
    }

    void deleteWaterBody() {
        waterMap.clear();
    }

    void printWaterBody() {
        std::cout << "  ";
        for (int i{ 0 }; i < colDimension; i++) {
            if (i < 10) std::cout << " " << i << " ";
            else std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "  ";
        for (int i{ 0 }; i < colDimension; i++) {
            std::cout << "---";
        }
        std::cout << std::endl;

        for (int i{ 97 }; i < (rowDimension + 97); i++) //97 is char "a" acording to ascii table
        {
            std::cout << char(i) << "|";
            for (int j{ 0 }; j < colDimension; j++) {
                std::cout << " " << char(126) << " "; //126 is char "~" acording to ascii table  

            }
            std::cout << std::endl;
        }
    }

    void setwaterType(std::string waterType_) {
        waterType = waterType_;
    }

    std::string getwaterType() {
        return waterType;
    }

    void setfishingPoint() {
        std::cout << "Enter point of fishing:";
        std::cin >> fishingPoint;
    }

    std::string getFish() {
        switch (waterMap[fishingPoint]) {
        case 1:
            return fish1;
        case 2:
            return fish2;
        case 3:
            return fish3;
        case 4:
            return fish4;
        case 0:
            return "No fish";
        }
    }

    void deleteFish() {
        waterMap[fishingPoint] = 0;
    }

private:
    int rowDimension;
    int colDimension;
    std::map<std::string, int> waterMap;
    std::string fishingPoint;
    std::string fish1, fish2, fish3, fish4;
    std::string waterType;
    std::string path;
};
