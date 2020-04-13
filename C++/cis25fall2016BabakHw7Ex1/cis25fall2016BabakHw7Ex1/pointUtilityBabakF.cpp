/*
program name: pointUtilityBabakF.cpp
Discussion:   Implementation -- Fraction Class
Writen by:    Babak
Due daate:    2016/11/17
*/


#include "pointBabakF.h"
#include "pointUtilityBabakF.h"
#include "fractionBabakF.h"

#include <iostream>
using namespace std;

void menu() {
	int xn, xd, yn, yd, distance;
	xd = yd = 1;
	xn = yn = distance = 0;
	int menuOption;
	int QOption;
	int Quadrant;
	fractionBabakF* X = new fractionBabakF(xn, xd);
	fractionBabakF* Y = new fractionBabakF(yn, yd);
	pointBabakF* firstPoint = nullptr;
	pointBabakF* secondPoint = nullptr;
	pointBabakF ResultHolder;

	int submenuOption;

	cout << "CIS 25 - C++ Programming\n"
		"Laney College\n"
		"Babak\n\n"

		"Assignment Information --\n"
		"  Assignment Number : Homework 06,\n"
		"                      Exercise #1\n"
		"Written by :          Babak Farahmand\n"
		"Due Date   :    2016/11/17" << endl;
	do {
		cout <<
			"\n*******************************\n"
			"*    MENU - HW #6             *\n"
			"*  1. Initializing (2 points) *\n"
			"*  2. Placement               *\n"
			"*  3. Moving                  *\n"
			"*  4. Flipping                *\n"
			"*  5. Displaying              *\n"
			"*  6. Quit                    *\n"
			"*******************************\n"
			"Select an option (use integer value only): ";
		cin >> menuOption;
		switch (menuOption) {
		case 1:
			do {
				cout <<
					"\n*******************************\n"
					"*    Sub Menu -- Initializing *\n"
					"*  1. Create(P1,P2)           *\n"
					"*  2. Update(P1,P2)           *\n"
					"*  3. Return to Previous MENU *\n"
					"*******************************\n"
					"Select an option(1, 2, or 3) : ";
				cin >> submenuOption;
				switch (submenuOption) {
				case 1:
					if (firstPoint == nullptr && secondPoint == nullptr)
						init(firstPoint, secondPoint);
					else
						cout << "\nYou already have points please select Update\n";
					break;
				case 2:
					if (firstPoint == nullptr && secondPoint == nullptr)
						cout << "\nYou don't have any points please create them\n";
					else
						update(firstPoint, secondPoint);
					break;
				case 3:
					submenuOption = 3;
					break;
				default:
					cout << "\nWrong Option!\n";
				}

			} while (submenuOption != 3);
			break;
		case 2:
			if (firstPoint == nullptr && secondPoint == nullptr)
				cout << "\nYou don't have any points please create them\n";
			else {
				do {
					cout <<
						"\n**********************************\n"
						"*      Sub Menu -- Quadrant      *\n"
						"* 1. Quadrant                    *\n"
						"* 2. Quadrant for specific point *\n"
						"* 3. Returning                   *\n"
						"**********************************\n"
						"Select an option(1, 2 or 3) : ";
					cin >> submenuOption;
					switch (submenuOption) {
					case 1:
						if (firstPoint == nullptr && secondPoint == nullptr)
							cout << "\nYou don't have any points please create them\n";
						else {
							Quadrant = firstPoint->getQuadrant();
							cout << "\nYour first point is in " << Quadrant << " Quadrant\n";
							Quadrant = secondPoint->getQuadrant();
							cout << "Your second points is in " << Quadrant << " Quadrant\n";
							Quadrant = 0;
						}
						break;
					case 2:
						if (firstPoint == nullptr && secondPoint == nullptr)
							cout << "\nYou don't have any points please create them\n";
						else {
							do {
								cout <<
									"\n**********************************************\n"
									"*      Sub Menu -- Quadrant(specific point)  *\n"
									"* 1. Quadrant for the first point            *\n"
									"* 2. Quadrant for the second point           *\n"
									"* 3. Returning to Quadratic menu             *\n"
									"**********************************************\n"
									"Select an option(1, 2, or 3) : ";
								cin >> QOption;



								switch (QOption)
								{
								case 1:
									cout << "\nYour first point respect to your second point is in "
										<< secondPoint->getQuadrant(*firstPoint) <<
										" Quadrant\n";
									break;
								case 2:
									cout << "\nYour first point respect to your second point is in "
										<< firstPoint->getQuadrant(*secondPoint) <<
										" Quadrant\n";
									break;
								case 3:
									QOption = 3;
								default:
									cout << "\nWrong option";
									break;
								}
							} while (QOption != 3);
							break;
					case 3:
						submenuOption = 3;
						break;
					default:
						cout << "\nWrong Option!\n";
						}
					}
				} while (submenuOption != 3);
			}
			break;
		case 3:
			if (firstPoint == nullptr && secondPoint == nullptr)
				cout << "\nYou don't have any points please create them\n";
			else {
				do {
					cout <<
						"\n********************************\n"
						"*   Sub Menu -- Moving Points  *\n"
						"* 1. By (frX , frY)            *\n"
						"* 2. By fr                     *\n"
						"* 3. printing                  *\n"
						"* 4. Returning                 *\n"
						"********************************\n"
						"Select an option(1, 2, 3, or 4) : ";
					cin >> submenuOption;
					switch (submenuOption) {
					case 1:

						cout << "\nPlease insert you destinition point followed by (X,Y)";
						cout << "\n  Insert you X numerator : ";
						cin >> xn;
						cout << "  Insert you X denominator : ";
						cin >> xd;
						X->update(xn, xd);
						cout << "\n  Insert you Y numerator : ";
						cin >> yn;
						cout << "  Insert you Y denominator : ";
						cin >> yd;
						Y->update(yn, yd);
						firstPoint->moveBy(*X, *Y);
						break;
					case 2:
						cout << "\nPlease insert you destinition distance :";
						cin >> distance;
						firstPoint->moveBy(distance);
						break;
					case 3:
						firstPoint->print();
						break;
					case 4:
						submenuOption = 4;
						break;
					default:
						cout << "\nWrong Option!\n";
					}
				} while (submenuOption != 4);
			}
			break;
		case 4:
			if (firstPoint == nullptr && secondPoint == nullptr)
				cout << "\nYou don't have any points please create them\n";
			else {
				do {
					cout <<
						"\n****************************\n"
						"* Sub Menu - FlippingPoint *\n"
						"*  1. By Y                 *\n"
						"*  2. By X                 *\n"
						"*  3. By Origin            *\n"
						"*  4. Printing             *\n"
						"*  5. Returning            *\n"
						"****************************\n"
						"Select an option(1, 2, 3, 4 or 5) : ";
					cin >> submenuOption;
					switch (submenuOption) {
					case 1:
						firstPoint->flipByY();
						break;
					case 2:
						firstPoint->flipByX();
						break;
					case 3:
						firstPoint->flipThroughOrigin();
						break;
					case 4:
						firstPoint->print();
						break;
					case 5:
						submenuOption = 5;
						break;
					default:
						cout << "\nWrong Option!\n";
					}
				} while (submenuOption != 5);
			}
			break;
		case 5:
			if (firstPoint == nullptr && secondPoint == nullptr)
				cout << "\nYou don't have any points please create them\n";
			else {
				do {
					cout <<
						"\n********************************\n"
						"*    Sub Menu -- PRINTING      *\n"
						"* (First Point, Second Point)  *\n"
						"* 1. print() - Member          *\n"
						"* 2. print() - Stand Alone     *\n"
						"* 3. ostream << -Stand Alone   *\n"
						"* 4. Returning                 *\n"
						"********************************\n"
						"Select an option(1, 2, or 3) :";
					cin >> submenuOption;
					switch (submenuOption) {
					case 1:
						if (firstPoint == nullptr && secondPoint == nullptr)
							cout << "\nYou don't have any points please create them\n";
						else {

							print((*firstPoint), (*secondPoint));
						}
						break;
					case 2:
						if (firstPoint == nullptr && secondPoint == nullptr)
							cout << "\nYou don't have any points please create them\n";
						else {
							firstPoint->print();
							secondPoint->print();
						}
						break;
					case 3:
						if (firstPoint == nullptr && firstPoint == nullptr)
							cout << "\nYou don't have any points please create them\n";
						else {
							cout << (*firstPoint) << (*secondPoint);
						}
						break;
					case 4:
						submenuOption = 4;
						break;
					default:
						cout << "\nWrong Option!\n";
					}
				} while (submenuOption != 4);
			}
			break;
		case 6:
			menuOption = 6;
			cout << "\nHaving Fun...\n";
		default:
			cout << "\nWrong Option!";
		}
	} while (menuOption != 6);
}

void update(pointBabakF*& firstPoint, pointBabakF*& secondPoint) {
	int nx;
	int dx;
	int ny;
	int dy;
	cout << "Enter the fist point\n"
		"  X coordinate ";
	cout << "\n    Numerator : ";
	cin >> nx;
	cout << "    Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n  Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n  Y coordinate \n";
	cout << "    Numerator : ";
	cin >> ny;
	cout << "   Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dy;
	}
	if (dy < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	firstPoint->update(nx, dx, ny, dy);
	cout << "\nEnter the second point\n"
		"  X coordinate";
	cout << "\n    Numerator : ";
	cin >> nx;
	cout << "    Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n  Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n  Y coordinate";
	cout << "\n    Numerator : ";
	cin >> ny;
	cout << "    Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dy;
	}
	if (dx < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	secondPoint->update(nx, dx, ny, dy);
	
}
void init(pointBabakF*& firstPoint, pointBabakF*& secondPoint) {
	int nx;
	int dx;
	int ny;
	int dy;
	cout << "Enter the fist point\n"
		"  X coordinate ";
	cout << "\n    Numerator : ";
	cin >> nx;
	cout << "    Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n  Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n  Y coordinate \n";
	cout << "    Numerator : ";
	cin >> ny;
	cout << "    Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n  Denominator : ";
		cin >> dy;
	}
	if (dy < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	firstPoint = new pointBabakF(nx, dx, ny, dy);
	cout << "\nEnter the second point\n"
		"  X coordinate";
	cout << "\n    Numerator : ";
	cin >> nx;
	cout << "    Denominator : ";
	cin >> dx;
	while (dx == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n  Denominator : ";
		cin >> dx;
	}
	if (dx < 0)
	{
		nx = -nx;
		dx = -dx;
	}
	cout << "\n  Y coordinate";
	cout << "\n    Numerator : ";
	cin >> ny;
	cout << "    Denominator : ";
	cin >> dy;
	while (dy == 0)
	{
		cout << "\nYou can't instert 0 in the denominator, please insert it again.\n";
		cout << "\n    Denominator : ";
		cin >> dy;
	}
	if (dy < 0)
	{
		ny = -ny;
		dy = -dy;
	}
	secondPoint = new pointBabakF(nx, dx, ny, dy);
}