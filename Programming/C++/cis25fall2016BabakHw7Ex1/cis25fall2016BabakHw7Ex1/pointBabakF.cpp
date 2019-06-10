/*
program name: pointBabakF.cpp
Discussion:   Implementation -- point Class
Writen by:    Babak
Due date:     2016/12/15
*/

#include "pointBabakF.h"
#include <iostream>
using namespace std;

pointBabakF::~pointBabakF()
{
}
fractionBabakF pointBabakF::getX(void) const {
	return fX;
}
fractionBabakF pointBabakF::getY(void) const {
	return fY;
}
void pointBabakF::setX(int nx, int dx) {
	fX.update(nx, dx);
}
void pointBabakF::setX(fractionBabakF& f) {
	fX = f;
}
void pointBabakF::setY(int ny, int dy) {
	fY.update(ny, dy);
}
void pointBabakF::setY(fractionBabakF& f) {
	fY = f;
}
void pointBabakF::update(int xn, int xd, int yn, int yd) {
	fX.update(xn, xd);
	fY.update(yn, yd);
}
int pointBabakF::getQuadrant() {
	if (fX.getNum() > 0 && fY.getNum() > 0)
		return 1;
	else if (fX.getNum() < 0 && fY.getNum() > 0)
		return 2;
	else if (fX.getNum() < 0 && fY.getNum() < 0)
		return 3;
	else if (fX.getNum() > 0 && fY.getNum() < 0)
		return 4;
	else
		return 0;
}
int pointBabakF::getQuadrant(const pointBabakF & p) {
	if (p.getX().getNum() > 0 && p.getY().getNum() > 0)
		return 1;
	else if (p.getX().getNum() < 0 && p.getY().getNum() > 0)
		return 2;
	else if (p.getX().getNum() < 0 && p.getY().getNum() < 0)
		return 3;
	else if (p.getX().getNum() > 0 && p.getY().getNum() < 0)
		return 4;
	else
		return 0;
}
void pointBabakF::moveBy(fractionBabakF delX, fractionBabakF delY) {
	int Xnum = delX.getNum();
	int Xdenom = delX.getDenom();
	int Ynum = delY.getNum();
	int Ydenom = delY.getDenom();
	delX = fractionBabakF(Xnum * fX.getDenom() - Xdenom * fX.getNum(), Xdenom * fX.getDenom());
	delY = fractionBabakF(Ynum * fY.getDenom() - Ydenom * fY.getNum(), Ydenom * fY.getDenom());
	fX = fX + delX;
	fY = fY + delY;
}
void pointBabakF::moveBy(int iOld) {
	fX = fX.add(iOld);
	fY = fY.add(iOld);
}
void pointBabakF::flipByX() {
	fX.setNum(-fX.getNum());
}
void pointBabakF::flipByY() {
	fY.setNum(-fY.getNum());
}
void pointBabakF::flipThroughOrigin() {
	fX.setNum(-fX.getNum());
	fY.setNum(-fY.getNum());
}
void pointBabakF::print() const {
	int numrator, num;
	numrator = num = fX.getNum();
	int denominator, denom;
	denominator = denom = fX.getDenom();
	int gcd = 1;
	for (int i = 2; i <= num && i <= denom; i++)
		if (num % i == 0 && denom % i == 0)
			gcd = i;
	numrator /= gcd;
	denominator /= gcd;
	cout << "  The current Point X value has\n"
		"    num : " << numrator << "\n"
		"    denom : " << denominator << "\n";
	numrator = num = fY.getNum();
	denominator = denom = fY.getDenom();
	gcd = 1;
	for (int i = 2; i <= num && i <= denom; i++)
		if (num % i == 0 && denom % i == 0)
			gcd = i;
	numrator /= gcd;
	denominator /= gcd;
	cout << "  The current Point Y value has\n"
		"    num : " << numrator << "\n"
		"    denom : " << denominator << "\n";
}