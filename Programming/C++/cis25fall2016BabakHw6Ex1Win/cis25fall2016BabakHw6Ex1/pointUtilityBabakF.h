/*
program name: pointUtilityBabakF.h
Discussion: Specification -- pointUtility Class
Writen by: Babak
Due daate: 2016/12/13
*/
#ifndef pointUtilityBabakF_H
#define pointUtilityBabakF_H
#include "fractionBabakF.h"

void menu(void);
void update(pointBabakF*& firstPoint, pointBabakF*& secondPoint);
void init(pointBabakF*& firstPoint, pointBabakF*& secondPoint);
void print(const pointBabakF& p1, const pointBabakF& p2) {
	int p1XNum,p1YNum,p2XNum,p2YNum;
	int p1XDenom,p1YDenom, p2XDenom,p2YDenom;
	//P1
	p1XNum =   p1.getX().getNum();
	p1XDenom = p1.getX().getDenom();
	p1YNum = p1.getY().getNum();
	p1YDenom = p1.getY().getDenom();
	//P2
	p2XNum = p2.getX().getNum();
	p2XDenom = p2.getX().getDenom();
	p2YNum = p2.getY().getNum();
	p2YDenom = p2.getY().getDenom();

	cout <<
		"         " << p1XNum << "   " << p1YNum<< " \n"
		"  P1 : ( - , - )\n"
		"         " << p1XDenom << "   " << p1YDenom << " " << endl;
	cout <<
		"         " << p2XNum << "   " << p2YNum << " \n"
		"  P2 : ( - , - )\n"
		"         " << p2XDenom << "   " << p2YDenom << " " << endl;
}
void print(const pointBabakF& p1) {
	int p1XNum, p1YNum;
	int p1XDenom, p1YDenom;
	p1XNum = p1.getX().getNum();
	p1XDenom = p1.getX().getDenom();
	p1YNum = p1.getY().getNum();
	p1YDenom = p1.getY().getDenom();

	cout <<
		"         " << p1XNum << "   " << p1YNum << " \n"
		"  P1 : ( - , - )\n"
		"         " << p1XDenom << "   " << p1YDenom << " " << endl;
}
#endif