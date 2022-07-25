// fishing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include "Menu.h"
#include "Players.h"
#include "fishes.h"
#include <Windows.h>
#include "water.h"

int WeightCarp{};
int WeightCrucian{};
int WeightPike{};
int saturation{ };
int valGear{};
int valBait{};
char bp;
std::string water;
char gear{};
char bait{};
Players::bait Plbt;

void Play();

void callMenu() {

	switch (mainMenu()) {
	case '1':
		char b;
		menuPlayers();
		b = _getch();
		while (b != '1' && b != '2') {
			b = _getch();
		}
		if (b == '1') {
			createPlayer();
			callMenu();
		}
		else if (b == '2') {
			existPlayers();

		}

		break;
	case '2':
		
		break;
	case '3':
		Play();
		break;
	case '4':
		exitPlay();

		break;



	}

}

void Play() {
	std::cout << "Choise a water : \n";
	menuChoiseWater();
char bp;
	bp = _getch();
	while (bp != '1' && bp != '2' && bp != '3') {
		bp = _getch();
	}
	if (bp == '1') { water = Lake::getNameWater(); }
	char gear{};
	char bait{};
	
	std::system("cls");
	std::cout << "Choise a fishing gear : \n"
		<< "1. Fishing Rod\n"
		<< "2. Spining\n";
	std::cin >> gear;
	 valGear = gear - 40;//transfotm char to int
	std::system("cls");
	std::cout << "Choise a bait : \n"
		<< "1. Worms\n"
		<< "2. Maggot\n"
		<< "3. Spoon\n";
	std::cin >> bait;
	valBait = bait - 40; //transfotm char to int

}



int main()
{
	Players Player;
	Carp Carp;
	Crucian Crucian;
	Pike Pike;
	Lake Lake;

	srand(time(NULL));
	callMenu();
	bool again{ true };

	while (again) {

		std::cout << "You cast your fishing rod...";
		Sleep(5000);

		if (Lake.WhatIsFish() == "Carp") {
			saturation = Carp.getSaturation();
			WeightCarp = Carp.getWeight();
			Plbt = Player.getBait(valBait);

		}
		if (Lake.WhatIsFish() == "Crucian") {
			saturation = Crucian.getSaturation();
			WeightCarp = Crucian.getWeight();
			Plbt = Player.getBait(valBait);;

		}
		if (Lake.WhatIsFish() == "Pike") {
			saturation = Pike.getSaturation();
			WeightCarp = Pike.getWeight();
			Plbt = Player.getBait(valBait);

		}

		Player.cautchFish(Player.getFishingGear(valGear), saturation, WeightCarp, Plbt);

		std::cout << "A G A I N ?\n"
			<< "Please press '1'\n"
			<< "Please press '0' for exit to Main Menu\n";
		char b;
		b = _getch();
		while (b != '1' && b != '0') {
			b = _getch();
		}
		if (b == '1') {
			bool again = true;

		}
		if (b == '0') {
			callMenu();

		}
	}

		return 0;
	}
		

	


