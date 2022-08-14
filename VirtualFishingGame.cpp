#include <iostream>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include <chrono>
#include "fish.h"
#include "Menu.h"
#include "Player.h"
#include "WaterBody.h"
#include "FishGear.h"
#include <Windows.h>

class Timer
{
public:
	void start() {
		startTime = std::chrono::system_clock::now();
	}

	int elapsedSeconds() {
		endTime = std::chrono::system_clock::now();
		return std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
	}
private:
	std::chrono::time_point<std::chrono::system_clock> startTime;
	std::chrono::time_point<std::chrono::system_clock> endTime;
};

int main()
{
	srand(time(NULL));
	static int sportFishingTime;
	static int amateurNumberFish;
	Menu menu;
	fish fish;
	player player;
	waterBody water;
	fishingRod rod;
	spinning spinning;
	Timer timer;

	do {
		//initial settings
		system("cls");
		menu.startInvestigation();
		player.setPlayerName();
		system("cls");
		menu.startInvestigation();
		menu.setGameType();
		system("cls");
		menu.startInvestigation();
		water.setwaterType(menu.selectWaterBody());
		system("cls");
		menu.startInvestigation();
		std::string strFishingGear = menu.selectFishGear();
		if (strFishingGear == "fishing rod") {
			rod.setFishGear(strFishingGear);
		}
		else
			spinning.setFishGear(strFishingGear);

		system("cls");
		menu.startInvestigation();
		rod.setBait(menu.setBait());
		system("cls");
		water.createWaterBody(water.getwaterType());
		timer.start();

		// Set different time and number of fish for different game type
		if (menu.getGameType() == 0) {
			sportFishingTime = 180; //time for sport fishing in seconds
			amateurNumberFish = 100; //number of fish in sport fishing in pcs
		}
		else {
			sportFishingTime = 3600; //time for amateur fishing in secomds
			amateurNumberFish = 10; //number of fish in amateur fishing in pcs
		}

		// Game cycles
		while (timer.elapsedSeconds() < sportFishingTime && player.getNumberOfFish() < amateurNumberFish) {
			system("cls");
			menu.startInvestigation();
			std::cout << "Player: " << player.getPlayerName() << "   Money: " << player.getMoney() << "    Caught fish: " << player.getNumberOfFish()
				<< "    Total fishes weight: " << fish.getTotalFishWeight() << "\n\n";
			std::cout << "Fishing gear: " << rod.getFishingGear() << "    Fishing bait: " << rod.getBait() << "\n\n";
			water.printWaterBody();
			int i = menu.gameControl();
			switch (i) {
			case 1:
				water.setwaterType(menu.selectWaterBody());
				water.deleteWaterBody();
				water.createWaterBody(water.getwaterType());
				player.subMoney(20); //pay for change water body
				break;
			case 2:
				strFishingGear = menu.selectFishGear();
				if (strFishingGear == "fishing rod") {
					rod.setFishGear(strFishingGear);
				}
				else
					spinning.setFishGear(strFishingGear);
				player.subMoney(10); //pay for change fish gear
				break;
			case 3:
				water.setfishingPoint();
				if (water.getFish() == "No fish") {
					std::cout << "There are no fish here, try again ";
					player.subMoney(3); //pay for fishing
					Sleep(3000);
					break;
				}
				else if (rod.getFishingGear() == "fishing rod" && player.pullFish(&rod) == true) {
					fish.getFishInfo(water.getFish());
					std::cout << "You caught a fish: " << water.getFish();
					player.setNumberOfFish(1);
					fish.getFishWeight();
					player.subMoney(3); //pay for fishing
					player.addMoney(fish.getPriceOfFish());
					water.deleteFish();
				}
				else if (spinning.getFishingGear() == "spinning" && player.pullFish(&spinning) == true) {
					fish.getFishInfo(water.getFish());
					std::cout << "You caught a fish: " << water.getFish();
					player.setNumberOfFish(1);
					fish.getFishWeight();
					player.subMoney(3); //pay for fishing
					player.addMoney(fish.getPriceOfFish());
					water.deleteFish();
				}
				else {
					std::cout << "Your fish will come off the hook";
					player.subMoney(3); //pay for fishing
				}
				Sleep(3000);
				break;
			case 4:
				rod.setBait(menu.setBait());
				player.subMoney(5); //pay for change bait
				break;
			}
			system("cls");
		}

		// Game over
		system("cls");
		menu.startInvestigation();
		std::cout << std::setw(44) << "GAME OVER" << "\n\n";
		std::cout << "Player: " << player.getPlayerName() << "   Money: " << player.getMoney() << "    Caught fish: " << player.getNumberOfFish()
			<< "    Total fishes weight: " << fish.getTotalFishWeight() << "   Elapsed time: " << timer.elapsedSeconds() << " sec" << "\n\n";
	} while (menu.gamePlay() == 1);
	water.deleteWaterBody();
	system("pause");
	return 0;

}

