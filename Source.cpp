#include"Bigfish.h"
#include<iostream>
#include<ctime>
#include<Windows.h>
#include <string>
#include <algorithm>
#include <list>
int main()
{
	BitingProcess bitingProcess;
	CatchInformation  information, exi;
	StartFishing startFishing,restart;
	StartFishing fishings(4);
	restart.change_location();
	bitingProcess.bait_change();
	srand(time(0));
	int w = 4;
	int f = 0;
	int fgh = 0;
	int count = 1;
	int input_ = 0;
	int choice = 0;
	int weight = 0;
	std::list<std::string> l = {};
	int hour = 0;
	exi.Menu();
	std::cout << "How much are you willing to pay. Write the dollar amount:" << std::endl;
	std::cin >> hour;
	std::cout << "You can catch:" << hour << "min." << std::endl;
	Sleep(3000);
	system("cls");
	std::cout << "What rod would you like to use?:" << std::endl;
	std::cout << "\n1.fishing_rod.\n2.spinning.\n3.screen." << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << "fishing_rod?!Not bad, not bad!" << std::endl;
		do
		{
			if (hour == 0)
			{
				std::cout << "Thank you!Would you like to fish more?\n";
				std::cout << "\n1. Yes, put 1 !\n2.Or not, put 2 ! \n";
				std::cin >> input_;
				Sleep(1000);
				system("cls");
				if (input_ == 2)
				{
					exit(0);
				}
				else
					std::cout << "If you wish to continue, you must pay extra. Write the dollar amount:" << std::endl;
				std::cin >> hour;
				std::cout << "You can catch:" << hour << "min." << std::endl;
				Sleep(2000);
				system("cls");
			}
			do
			{
				information.Catch_In_formation();
				hour--;
				if (fishings == 4)
				{
					fgh = rand() % 2 + 1;
					if (fgh == 1)
					{
						f = rand() % 8 + 1;
						if (f == 1)
						{
							std::cout << " nothing" << std::endl;
							Sleep(1000);
							system("cls");
						}
						else if (f == 2)
						{
							l.push_front("perch ");
							std::cout << "Its ok! Its ok!\n";
							weight = rand() % 7 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
							Sleep(5000);
							system("cls");
						}
						else if (f == 3)
						{
							std::cout << " o nou!" << std::endl;
							Sleep(1000);
							system("cls");
						}
						else if (f == 4)
						{
							l.push_front("perch ");
							std::cout << "Its ok! Its ok!\n";
							weight= rand() % 7 + 1;
							if(weight>5)
							std::cout << "It's not a perch, it's a whole shark!His weight\n"<< weight<<" kilogram!";
							else
								std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
							Sleep(5000);
							system("cls");
						}
						else if (f == 5)
						{
							std::cout << " It's definitely not my day!Rushed again! " << std::endl;
							Sleep(2000);
							system("cls");
						}
						else if (f == 6)
						{
							l.push_front("catfish");
							std::cout << "Yeeeaa!\n";
							weight = rand() % 15 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight\n " << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!whole\n" << weight << " kilogram!";
							Sleep(5000);
							system("cls");
						}
						else if (f == 7)
						{
							l.push_front("catfish");
							std::cout << "Yeeeaa!\n";
							weight = rand() % 15 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight\n " << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!whole\n " << weight << " kilogram!";
							Sleep(5000);
							system("cls");
						}
					}
					else
						f = rand() % 15 + 8;
					if (f == 8)
					{
						std::cout << " nothing1" << std::endl;
						Sleep(2000);
						system("cls");
					}
					else if (f == 9)
					{
						l.push_front("ramming ");
						std::cout << "Ohohohoo!Pecking!\n";
						weight = rand() % 3 + 1;
							std::cout << "Whole " << weight << " vkilogram!";
                        Sleep(5000);
						system("cls");
					}
					else if (f == 10)
					{
						std::cout << " Where is the fish?!" << std::endl;
						Sleep(2000);
						system("cls");
					}
					else if (f == 11)
					{
						l.push_front("perch ");
						std::cout << "Pecking!\n";
						weight = rand() % 8 + 1;
						if (weight > 4)
							std::cout << "I haven't seen this yet! \n" << weight << " kilogram!";
						else
							std::cout << "At least something \n" << weight << " kilogram!";
						Sleep(5000);
						system("cls");
					}
					else if (f == 12)
					{
						std::cout << " Why not! " << std::endl;
						Sleep(1000);
						system("cls");
					}
					else if (f == 13)
					{
						l.push_front("perch ");
						std::cout << "Yess!\n";
						weight = rand() % 8 + 1;
						if (weight > 4)
							std::cout << "I haven't seen this yet! \n" << weight << " kilogram!";
						else
							std::cout << "At least something \n" << weight << " kilogram!";
						Sleep(5000);
						system("cls");
					}
					else if (f == 14)
					{
						std::cout << "Shoe!? Hm!\n";
						Sleep(2000);
						system("cls");
					}
					for (std::string n : l) {

						std::cout << n << " ";
						count++;
					}
					std::cout << "\n";
				}
				else
					std::cout << "sorry!\n";
			} while (hour != 0);
		} while (true);
		break;
	case 2:
		std::cout << "spinning?!This is power!" << std::endl;
		do
		{
			if (hour == 0)
			{
				std::cout << "Thank you!Would you like to fish more?\n";
				std::cout << "\n1. Yes, put 1 !\n2.Or not, put 2 ! \n";
				std::cin >> input_;
				Sleep(1000);
				system("cls");
				if (input_ == 2)
				{
					exit(0);
				}
				else
					std::cout << "If you wish to continue, you must pay extra. Write the dollar amount:" << std::endl;
				std::cin >> hour;
				std::cout << "You can catch:" << hour << "min." << std::endl;
				Sleep(2000);
				system("cls");
			}
			do
			{
				information.Catch_In_formation();
				hour--;
				if (fishings == 4)
				{
					fgh = rand() % 2 + 1;
					if (fgh == 1)
					{
						f = rand() % 8 + 1;
						if (f == 1)
						{
							l.push_front("perch ");
							std::cout << "Its ok! Its ok!\n";
							weight = rand() % 7 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
							Sleep(5000);
							system("cls");
						}
						else if (f == 2)
						{
							l.push_front("zander");
							std::cout << "Gooood daaay!\n";
							weight = rand() % 7 + 1;
							if (weight > 5)
								std::cout << "Hoo hooo, it's a zander!His weight \n" << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
							Sleep(1000);
							system("cls");
						}
						else if (f == 3)
						{
							std::cout << " o nou!" << std::endl;
							Sleep(1000);
							system("cls");
						}
						else if (f == 4)
						{
							l.push_front("perch ");
							std::cout << "Its ok! Its ok!\n";
							weight = rand() % 7 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
							Sleep(5000);
							system("cls");
						}
						else if (f == 5)
						{
							std::cout << " It's definitely not my day! " << std::endl;
							Sleep(2000);
							system("cls");
						}
						else if (f == 6)
						{
							l.push_front("catfish");
							std::cout << "Yeeeaa!\n";
							weight = rand() % 15 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight\n " << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!whole\n" << weight << " kilogram!";
							Sleep(5000);
							system("cls");
						}
						else if (f == 7)
						{
							std::cout << " Neither fish nor worm!\n";
							Sleep(1000);
							system("cls");
						}
					}
					else
						f = rand() % 15 + 8;
					if (f == 8)
					{
						std::cout << " nothing1" << std::endl;
						Sleep(2000);
						system("cls");
					}
					else if (f == 9)
					{
						l.push_front("ramming ");
						std::cout << "Ohohohoo!Pecking!\n";
						weight = rand() % 3 + 1;
						std::cout << "Whole " << weight << " vkilogram!";
						Sleep(5000);
						system("cls");
					}
					else if (f == 10)
					{
						std::cout << " Where is the fish?!" << std::endl;
						Sleep(2000);
						system("cls");
					}
					else if (f == 11)
					{
						l.push_front("perch ");
						std::cout << "Its ok! Its ok!\n";
						weight = rand() % 7 + 1;
						if (weight > 5)
							std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
						else
							std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
						Sleep(5000);
						system("cls");
					}
					else if (f == 12)
					{
						std::cout << " Why not! " << std::endl;
						Sleep(2000);
						system("cls");
					}
					else if (f == 13)
					{
						l.push_front("catfish");
						std::cout << "Yeeeaa!\n";
						weight = rand() % 15 + 1;
						if (weight > 5)
							std::cout << "It's not a perch, it's a whole shark!His weight\n " << weight << " kilogram!";
						else
							std::cout << "I won't leave empty handed!whole\n" << weight << " kilogram!";
						Sleep(5000);
						system("cls");
					}
					else if (f == 14)
					{
						std::cout << "Shoe!? Hm!\n";
						Sleep(2000);
						system("cls");
					}
					for (std::string n : l) {

						std::cout << n << " \n";
						count++;
					}
					std::cout << "\n";
				}
				else
					std::cout << "sorry!\n";
			} while (hour != 0);
		} while (true);
		break;
	case 3:
		std::cout << "screen?!It's easy money!" << std::endl;
		do
		{
            if (hour == 0)
			{
				std::cout << "Thank you!Would you like to fish more?\n";
				std::cout << "\n1. Yes, put 1 !\n2.Or not, put 2 ! \n";
				std::cin >> input_;
				Sleep(1000);
				system("cls");
				if (input_ == 2)
				{
					exit(0);
				}
				else
					std::cout << "If you wish to continue, you must pay extra. Write the dollar amount:" << std::endl;
				std::cin >> hour;
				std::cout << "You can catch:" << hour << "min." << std::endl;
				Sleep(2000);
				system("cls");
			}
			do
			{
				information.Catch_In_formation();
				hour--;
				if (fishings == 4)
				{
					fgh = rand() % 2 + 1;
					if (fgh == 1)
					{
						f = rand() % 8 + 1;
						if (f == 1)
						{
							std::cout << " nothing" << std::endl;
							Sleep(1000);
							system("cls");
						}
						else if (f == 2)
						{
							l.push_front("crucian ");
							std::cout << "Ohohohoo!Pecking!\n";
							Sleep(1000);
							system("cls");
						}
						else if (f == 3)
						{
							l.push_front("perch ");
							std::cout << "Its ok! Its ok!\n";
							weight = rand() % 7 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
							Sleep(5000);
							system("cls");
						}
						else if (f == 4)
						{
							l.push_front("perch ");
							std::cout << "Its ok! Its ok!\n";
							weight = rand() % 7 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
							Sleep(5000);
							system("cls");
						}
						else if (f == 5)
						{
							std::cout << " It's definitely not my day! " << std::endl;
							Sleep(2000);
							system("cls");
						}
						else if (f == 6)
						{
							l.push_front("catfish");
							std::cout << "Yeeeaa!\n";
							weight = rand() % 15 + 1;
							if (weight > 5)
								std::cout << "It's not a perch, it's a whole shark!His weight\n " << weight << " kilogram!";
							else
								std::cout << "I won't leave empty handed!whole\n " << weight << " kilogram!";
							Sleep(5000);
							system("cls");
						}
						else if (f == 7)
						{
							std::cout << " Neither fish nor worm!\n";
							Sleep(1000);
							system("cls");
						}
					}
					else
						f = rand() % 15 + 8;
					if (f == 8)
					{
						std::cout << " nothing1" << std::endl;
						Sleep(2000);
						system("cls");
					}
					else if (f == 9)
					{
						l.push_front("ramming ");
						std::cout << "Ohohohoo!Pecking!\n";
						weight = rand() % 3 + 1;
						std::cout << "Whole " << weight << " vkilogram!";
						Sleep(5000);
						system("cls");
					}
					else if (f == 10)
					{
						std::cout << " Where is the fish?!" << std::endl;
						Sleep(2000);
						system("cls");
					}
					else if (f == 11)
					{
						l.push_front("perch ");
						std::cout << "Its ok! Its ok!\n";
						weight = rand() % 7 + 1;
						if (weight > 5)
							std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
						else
							std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
						Sleep(5000);
						system("cls");
					}
					else if (f == 12)
					{
						l.push_front("perch ");
						std::cout << "Its ok! Its ok!\n";
						weight = rand() % 7 + 1;
						if (weight > 5)
							std::cout << "It's not a perch, it's a whole shark!His weight \n" << weight << " kilogram!";
						else
							std::cout << "I won't leave empty handed!\n" << weight << " kilogram!";;
						Sleep(5000);
						system("cls");
					}
					else if (f == 13)
					{
						l.push_front("catfish");
						std::cout << "Yeeeaa!\n";
						weight = rand() % 15 + 1;
						if (weight > 5)
							std::cout << "It's not a perch, it's a whole shark!His weight\n " << weight << " kilogram!";
						else
							std::cout << "I won't leave empty handed!whole\n " << weight << " kilogram!";
						Sleep(5000);
						system("cls");
					}
					else if (f == 14)
					{
						std::cout << "Shoe!? Hm!\n";
						Sleep(2000);
						system("cls");
					}
					for (std::string n : l) {

						std::cout << n << " ";
						count++;
					}
					std::cout << "\n";
				}
				else
					std::cout << "sorry!\n";
			} while (hour != 0);
		} while (true);
		break;
	}
     std::cout << "Thank you! Here you are always welcome!\n";
	return 0;
}
