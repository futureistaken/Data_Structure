/*
program name: pointUtilityBabakF.cpp
Discussion:   Implementation -- Fraction Class
Writen by:    Babak
Due daate:    2016/12/15
*/


#include "pointBabakF.h"
#include "fractionBabakF.h"
#include "circleUtilityBabakF.h"
#include "circleBabakF.h"

#include <iostream>
using namespace std;

void menu() {
	int xn, xd, yn, yd, distance, position;
	xd = yd = 1;
	xn = yn = distance = 0;
	int menuOption, submenuOption, subSubMenuOption;
	circleBabakF* firstCircle = nullptr;
	circleBabakF* secondCircle = nullptr;
	fractionBabakF* X = new fractionBabakF(xn, xd);
	fractionBabakF* Y = new fractionBabakF(yn, yd);

	cout << "CIS 25 - C++ Programming\n"
		"Laney College\n"
		"Babak\n\n"

		"Assignment Information --\n"
		"  Assignment Number: Homework 7,\n"
		"                      Exercise #1\n"
		"  Written by:         Babak Farahmand\n"
		"  Due Date:           2016/12/15" << endl;
	do {
		cout <<
			"\n********************************\n"
			"*          MENU - HW #7        *\n"
			"*  1. Initializing (2 circles) *\n"
			"*  2. Positioning              *\n"
			"*  3. Moving                   *\n"
			"*  4. Comparing                *\n"
			"*  5. Displaying               *\n"
			"*  6. Quit                     *\n"
			"********************************\n"
			"Select an option (use integer value only): ";
		cin >> menuOption;
		while (cin.fail())
		{
			cout <<
				"\n**********************************************************\n"
				"*WARNING, You should only use integers to work with menu,*\n"
				"**********************************************************\n"
				"Re-select an option from Menu(use integer value only) : ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> menuOption;
		}
		switch (menuOption) {
		case 1:
			do {
				cout <<
					"\n  ********************************\n"
					"  *    Sub Menu -- Initializing  *\n"
					"  *  1. Create(Circle1, Circle2) *\n"
					"  *  2. Update(Circle1, Circle2) *\n"
					"  *  3. Displaying               *\n"
					"  *  4. Return to Previous MENU  *\n"
					"  ********************************\n"
					"  Select an option (use integer value only): ";
				cin >> submenuOption;
				while (cin.fail())
				{
					cout <<
						"\n**********************************************************\n"
						"*WARNING, You should only use integers to work with menu,*\n"
						"**********************************************************\n"
						"  Re-select an option from Menu(use integer value only) : ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> submenuOption;
				}
				switch (submenuOption) {
				case 1:
					if (firstCircle == nullptr && secondCircle == nullptr)
						init(firstCircle, secondCircle);
					else
						cout << "\n  You already have Circles please select Update\n";
					break;
				case 2:
					if (firstCircle == nullptr && secondCircle == nullptr)
						cout << "\n  You don't have any Circles please create them\n";
					else
						update(firstCircle, secondCircle);
					break;
				case 3:
					if (firstCircle == nullptr && secondCircle == nullptr)
						cout << "\n  You don't have any Circles please create them\n";
					else
					{
						cout << "\n"
							"  **************"
							"\n  *First Circle*\n"
							"  **************\n";
						firstCircle->print();
						cout << "\n"
							"  ***************"
							"\n  *Second Circle*\n"
							"  ***************\n";
						secondCircle->print();
					}
					break;
				case 4:
					submenuOption = 4;
					break;
				default:
					cout << "\n  Wrong Option!\n";
				}

			} while (submenuOption != 4);
			break;
		case 2:
			if (firstCircle == nullptr && secondCircle == nullptr)
				cout << "\nYou don't have any Circles please create them\n";
			else {
				position = firstCircle->position(secondCircle);
				switch (position)
				{
				case 0:
					cout << "\nCircles are inside of each other with a same center and with a same radius.\n";
					cout << "\n"
						"**************"
						"\n*First Circle*\n"
						"**************\n";
					firstCircle->print();
					cout << "\n"
						"***************"
						"\n*Second Circle*\n"
						"***************\n";
					secondCircle->print();
					break;
				case 1:
					cout << "\nCircles are outside and they might touch each others curve.\n";
					cout << "\n"
						"**************"
						"\n*First Circle*\n"
						"**************\n";
					firstCircle->print();
					cout << "\n"
						"***************"
						"\n*Second Circle*\n"
						"***************\n";
					secondCircle->print();
					break;
				case 2:
					cout << "\nCircles are inside of each other with a diferent center.\n";
					cout << "\n"
						"**************"
						"\n*First Circle*\n"
						"**************\n";
					firstCircle->print();
					cout << "\n"
						"***************"
						"\n*Second Circle*\n"
						"***************\n";
					secondCircle->print();
					break;
				case 3:
					cout << "\nCircles are overlaping ceach other and the center of the small circle is inside of the big cicel.\n";
					cout << "\n"
						"**************"
						"\n*First Circle*\n"
						"**************\n";
					firstCircle->print();
					cout << "\n"
						"***************"
						"\n*Second Circle*\n"
						"***************\n";
					secondCircle->print();
					break;
				case 4:
					cout << "\nCircles are overlaping ceach other.\n";
					cout << "\n"
						"**************"
						"\n*First Circle*\n"
						"**************\n";
					firstCircle->print();
					cout << "\n"
						"***************"
						"\n*Second Circle*\n"
						"***************\n";
					secondCircle->print();
					break;
				case 5:
					cout << "\n No Positon Found!!!\n";
					cout << "\n"
						"**************"
						"\n*First Circle*\n"
						"**************\n";
					firstCircle->print();
					cout << "\n"
						"***************"
						"\n*Second Circle*\n"
						"***************\n";
					secondCircle->print();
					break;
				case 6:
					cout << "\ncircles are inside of each other with a same center.\n";
					cout << "\n"
						"**************"
						"\n*First Circle*\n"
						"**************\n";
					firstCircle->print();
					cout << "\n"
						"***************"
						"\n*Second Circle*\n"
						"***************\n";
					secondCircle->print();
					break;
				}
			}
			break;
		case 3:
			if (firstCircle == nullptr && secondCircle == nullptr)
				cout << "\nYou don't have any Circles please create them\n";
			else {
				do {
					cout <<
						"\n  ********************************\n"
						"  *   Sub Menu -- Moving Circles *\n"
						"  * 1. Horizontally              *\n"
						"  * 2. Vertically                *\n"
						"  * 3. Displaying                *\n"
						"  * 4. Returning                 *\n"
						"  ********************************\n"
						"  Select an option (use integer value only): ";
					cin >> submenuOption;
					while (cin.fail())
					{
						cout <<
							"\n**********************************************************\n"
							"*WARNING, You should only use integers to work with menu,*\n"
							"**********************************************************\n"
							"  Re-select an option from Menu(use integer value only) : ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> submenuOption;
					}
					switch (submenuOption) {
					case 1:
						do {
							cout <<
								"\n    *******************************************\n"
								"    *   Sub Menu -- Moving Horizontally       *\n"
								"    *              (With respect to Circle 1) *\n"
								"    * 1. By an int                            *\n"
								"    * 2. By a Fraction                        *\n"
								"    * 3. Displaying                           *\n"
								"    * 4. Returning                            *\n"
								"    *******************************************\n"
								"    Select an option (use integer value only): ";
							cin >> subSubMenuOption;
							while (cin.fail())
							{
								cout <<
									"\n  **********************************************************\n"
									"  *WARNING, You should only use integers to work with menu,*\n"
									"  **********************************************************\n"
									"    Re-select an option from Menu(use integer value only) : ";
								cin.clear();
								cin.ignore(256, '\n');
								cin >> subSubMenuOption;
							}
							switch (subSubMenuOption) {
							case 1:
								cout << "\n    Please Insert an Integer to move the second circle respect to the first circle : ";
								cin >> distance;
								secondCircle->moveByIntH(distance, firstCircle);
								break;
							case 2:
								cout << "\n    Please insert you fraction: ";
								cout << "\n      Insert you X numerator : ";
								cin >> xn;
								cout << "        Insert you X denominator : ";
								cin >> xd;
								X->update(xn, xd);
								secondCircle->moveByFractionH((*X), firstCircle);
								break;
							case 3:
								cout << "\n"
									"    **************"
									"\n    *First Circle*\n"
									"    **************\n";
								firstCircle->print();
								cout << "\n"
									"    ***************"
									"\n    *Second Circle*\n"
									"    ***************\n";
								secondCircle->print();
								break;
							case 4:
								subSubMenuOption = 4;
								break;
							default:
								cout << "\n    Wrong Option!\n";
								break;
							}
						} while (subSubMenuOption != 4);
						break;
					case 2:
						do {
							cout <<
								"\n    *******************************************\n"
								"    *   Sub Menu -- Moving Vertically         *\n"
								"    *              (With respect to Circle 1) *\n"
								"    * 1. To get a distance of an int          *\n"
								"    * 2. To get a distance of a Fraction      *\n"
								"    * 3. Displaying                           *\n"
								"    * 4. Returning                            *\n"
								"    *******************************************\n"
								"    Select an option (use integer value only): ";
							cin >> subSubMenuOption;
							while (cin.fail())
							{
								cout <<
									"\n  **********************************************************\n"
									"  *WARNING, You should only use integers to work with menu,*\n"
									"  **********************************************************\n"
									"    Re-select an option from Menu(use integer value only) : ";
								cin.clear();
								cin.ignore(256, '\n');
								cin >> subSubMenuOption;
							}
							switch (subSubMenuOption) {
							case 1:
								cout << "\n    Please Insert an Integer to move the second circle respect to the first circle : ";
								cin >> distance;
								secondCircle->moveByIntY(distance, firstCircle);
								break;
							case 2:
								cout << "\n    Please insert you fraction: ";
								cout << "\n      Insert you X numerator : ";
								cin >> xn;
								cout << "		 Insert you X denominator : ";
								cin >> xd;
								Y->update(xn, xd);
								secondCircle->moveByFractionY((*Y), firstCircle);
								break;
							case 3:
								cout << "\n"
									"    **************"
									"\n    *First Circle*\n"
									"    **************\n";
								firstCircle->print();
								cout << "\n"
									"    ***************"
									"\n    *Second Circle*\n"
									"    ***************\n";
								break;
							case 4:
								subSubMenuOption = 4;
								break;
							default:
								cout << "\n    Wrong Option!\n";
								break;
							}
						} while (subSubMenuOption != 4);
						break;
					case 3:
						cout << "\n"
							"  **************"
							"\n  *First Circle*\n"
							"  **************\n";
						firstCircle->print();
						cout << "\n"
							"  ***************"
							"\n  *Second Circle*\n"
							"  ***************\n";
						secondCircle->print();
						break;
					case 4:
						submenuOption = 4;
						break;
					default:
						cout << "\n    Wrong Option!\n";
					}
				} while (submenuOption != 4);
			}
			break;
		case 4:
			if (firstCircle == nullptr && secondCircle == nullptr)
				cout << "\nYou don't have any Circles please create them\n";
			else {
				do {
					cout <<
						"\n  *******************************************\n"
						"  *   Sub Menu -- Comparing                 *\n"
						"  *              (With respect to Circle 1) *\n"
						"  * 1. Using area with PI of 157/50         *\n"
						"  * 2. Using perimeter with PI of 157/50    *\n"
						"  * 3. Displaying                           *\n"
						"  * 4. Returning                            *\n"
						"  *******************************************\n"
						"  Select an option (use integer value only): ";
					cin >> submenuOption;
					while (cin.fail())
					{
						cout <<
							"\n**********************************************************\n"
							"*WARNING, You should only use integers to work with menu,*\n"
							"**********************************************************\n"
							"  Re-select an option from Menu(use integer value only) : ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> submenuOption;
					}
					switch (submenuOption) {
					case 1:
						if (firstCircle->computeArea() > secondCircle->computeArea())
						{
							cout << "\n"
								"  **************"
								"\n  *First Circle*\n"
								"  **************\n";
							firstCircle->print();
							firstCircle->printArea();
							cout << "\n Has larger area than\n";
							cout << "\n"
								"  ***************"
								"\n  *Second Circle*\n"
								"  ***************\n";
							secondCircle->print();
							secondCircle->printArea();
						}
						else if (firstCircle->computeArea() < secondCircle->computeArea())
						{
							cout << "\n"
								"  ***************"
								"\n  *Second Circle*\n"
								"  ***************\n";
							secondCircle->print();
							secondCircle->printArea();
							cout << "\n Has larger area than\n";
							cout << "\n"
								"  **************"
								"\n  *First Circle*\n"
								"  **************\n";
							firstCircle->print();
							firstCircle->printArea();
						}
						else
						{
							
							cout << "\n"
								"  ***************"
								"\n  *Second Circle*\n"
								"  ***************\n";
							secondCircle->print();
							secondCircle->printArea();
							cout << "\n Both circles have same area.\n";
							cout << "\n"
								"  **************"
								"\n  *First Circle*\n"
								"  **************\n";
							firstCircle->print();
							firstCircle->printArea();
						}
						break;
					case 2:
						if (firstCircle->computePerimeter() > secondCircle->computePerimeter())
						{
							cout << "\n"
								"  **************"
								"\n  *First Circle*\n"
								"  **************\n";
							firstCircle->print();
							firstCircle->printPerimeter();
							cout << "\n Has larger perimeter than\n";
							cout << "\n"
								"  ***************"
								"\n  *Second Circle*\n"
								"  ***************\n";
							secondCircle->print();
							secondCircle->printPerimeter();
						}
						else if (firstCircle->computePerimeter() > secondCircle->computePerimeter())
						{
							cout << "\n"
								"  ***************"
								"\n  *Second Circle*\n"
								"  ***************\n";
							secondCircle->print();
							secondCircle->printPerimeter();
							cout << "\n Has larger perimeter than\n";
							cout << "\n"
								"  **************"
								"\n  *First Circle*\n"
								"  **************\n";
							firstCircle->print();
							firstCircle->printPerimeter();
						}
						else
						{
							cout << "\n"
								"  ***************"
								"\n  *Second Circle*\n"
								"  ***************\n";
							secondCircle->print();
							secondCircle->printArea();
							cout << "\n Both circles have same perimeter.\n";
							cout << "\n"
								"  **************"
								"\n  *First Circle*\n"
								"  **************\n";
							firstCircle->print();
							firstCircle->printArea();
						}
							break;
					case 3:
						cout << "\n"
							"  **************"
							"\n  *First Circle*\n"
							"  **************\n";
						firstCircle->print();
						cout << "\n"
							"  ***************"
							"\n  *Second Circle*\n"
							"  ***************\n";
						secondCircle->print();
						break;
					case 4:
						submenuOption = 4;
						break;
					default:
						cout << "\n  Wrong Option!\n";
						break;
					}

				} while (submenuOption != 4);
			}
			break;
		case 5:
			if (firstCircle == nullptr && secondCircle == nullptr)
				cout << "\nYou don't have any Circles please create them\n";
			else
			{
				cout << "\n"
					"**************"
					"\n*First Circle*\n"
					"**************\n";
				firstCircle->print();
				cout << "\n"
					"***************"
					"\n*Second Circle*\n"
					"***************\n";
				secondCircle->print();
			}
			break;
		case 6:
			delete firstCircle;
			delete secondCircle;
			delete X;
			delete Y;
			menuOption = 6;
			cout << "\nHaving Fun...\n";
			break;
		default:
			cout << "\nWrong Option!\n";
		}
	} while (menuOption != 6);
}
void update(circleBabakF*& firstCircle, circleBabakF*& secondCircle) {
	int nx;
	int dx;
	int ny;
	int dy;
	int rn;
	int rd;
	cout << "  Enter the center for the first circle\n"
		"    X coordinate ";
	cout << "\n      Numerator : ";
	cin >> nx;
	cout << "      Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n    Y coordinate \n";
	cout << "      Numerator : ";
	cin >> ny;
	cout << "      Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dy;
	}
	if (dy < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	cout << "\n  Please Insert Radius for the first circle\n";
	cout << "    Numerator : ";
	cin >> rn;;
	cout << "    Denominator : ";
	cin >> rd;
	while (rd == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> rd;
	}
	if (rd < 0)
	{
		rn = -rn;
		rd = -rd;
	}
	firstCircle->update(nx, dx, ny, dy, rn, rd);
	cout << "*********************************************";
	cout << "\n  Enter the center for the  second circle\n"
		"    X coordinate ";
	cout << "\n      Numerator : ";
	cin >> nx;
	cout << "      Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n    Y coordinate \n";
	cout << "      Numerator : ";
	cin >> ny;
	cout << "      Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dy;
	}
	if (dy < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	cout << "\n  Please Insert Radius for the Second circle\n";
	cout << "    Numerator : ";
	cin >> rn;;
	cout << "    Denominator : ";
	cin >> rd;
	while (rd == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> rd;
	}
	if (rd < 0)
	{
		rn = -rn;
		rd = -rd;
	}
	secondCircle->update(nx, dx, ny, dy, rn, rd);
}
void init(circleBabakF*& firstCircle, circleBabakF*& secondCircle) {
	int nx;
	int dx;
	int ny;
	int dy;
	int rn;
	int rd;
	cout << "  Enter the center for the first circle\n"
		"    X coordinate ";
	cout << "\n      Numerator : ";
	cin >> nx;
	cout << "      Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n    Y coordinate \n";
	cout << "      Numerator : ";
	cin >> ny;
	cout << "      Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dy;
	}
	if (dy < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	cout << "\n  Please Insert Radius for the first circle\n";
	cout << "    Numerator : ";
	cin >> rn;;
	cout << "    Denominator : ";
	cin >> rd;
	while (rd == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> rd;
	}
	if (rd < 0)
	{
		rn = -rn;
		rd = -rd;
	}
	firstCircle = new circleBabakF(nx, dx, ny, dy, rn, rd);
	cout << "*********************************************";
	cout << "\n  Enter the center for the  second circle\n"
		"    X coordinate ";
	cout << "\n      Numerator : ";
	cin >> nx;
	cout << "      Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n    Y coordinate \n";
	cout << "      Numerator : ";
	cin >> ny;
	cout << "      Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dy;
	}
	if (dy < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	cout << "\n  Please Insert Radius for the Second circle\n";
	cout << "    Numerator : ";
	cin >> rn;;
	cout << "    Denominator : ";
	cin >> rd;
	while (rd == 0)
	{
		cout << "\n  You can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> rd;
	}
	if (rd < 0)
	{
		rn = -rn;
		rd = -rd;
	}
	secondCircle = new circleBabakF(nx, dx, ny, dy, rn, rd);
}