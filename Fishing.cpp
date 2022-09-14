#include <iostream>
#include <string>
#include <chrono>

#include "Fish.h"
#include "Water.h"
#include "Bait.h"
#include "ReadFromFile.h"
#include "Game.h"
#include "Menu.h"
#include "WriteToFile.h"

int main() {
    srand( time( nullptr ) );
    int timeOfGame {};

    //fish
    Crucian crucian;
    Perch perch;
    Pike pike;

    //water
    River river;
    Lake lake;
    Reservoir reservoir;

    //bait
    Bait bloodworm;
    Bait earthworm;
    Bait maggot;

    ReadFromFile::readFishFromFile( crucian, perch, pike );
    ReadFromFile::readBaitFromFile( bloodworm, earthworm, maggot );
    ReadFromFile::readWaterFromFile( river, lake, reservoir );

    Game game( river, lake, reservoir, crucian, perch, pike, bloodworm, earthworm, maggot );
    int choise {};


    game.catching();

    do {
        auto begin { std::chrono::steady_clock::now() };
        
        Menu::choiseMenu( game, choise );

        timeOfGame += std::chrono::duration_cast< std::chrono::minutes >( std::chrono::steady_clock::now() - begin ).count();

    } while( choise != static_cast< int > ( Menu::EndOfFishing ) && game.getCurrentFishWeight() <= game.getPaidFishWeight() && timeOfGame < game.getCurrentFishingTime() );


    std::cout << std::endl << "Your fishing is finished!" << std::endl << std::endl;
    game.checkCurrentCatch();
    WriteToFile::writeToFile( "Data\\Result.txt", game.getCurrentCatch() );

    return 0;
}
