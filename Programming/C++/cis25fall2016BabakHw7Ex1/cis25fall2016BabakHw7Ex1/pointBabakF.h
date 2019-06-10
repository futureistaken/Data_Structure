/*
program name: pointBabakF.H
Discussion:   Specification -- point Class
Writen by:    Babak
Due daate:    2016/12/15
*/

#ifndef pointBabakF_H
#define pointBabakF_H
#include "fractionBabakF.h"

class pointBabakF {
public:
	pointBabakF() :fX(), fY() {};//default constructor,
	pointBabakF(int nx, int dx, int ny, int dy) : fX(nx, dx), fY(ny, dy) {};//copy contructor,
	~pointBabakF();//destructor
	fractionBabakF getX(void) const;
	fractionBabakF getY(void) const;
	void setX(int, int);
	void setX(fractionBabakF & f);
	void setY(int, int);
	void setY(fractionBabakF & f);
	void update(int, int, int, int);
	// operations
	int getQuadrant();
	int getQuadrant(const pointBabakF& p);
	void moveBy(fractionBabakF delX, fractionBabakF delY);
	void moveBy(int iOld);
	void flipByX();
	void flipByY();
	void flipThroughOrigin();
	void print() const;
	friend ostream& operator<<(ostream& o, const pointBabakF& f) {
		int numrator, num;
		numrator = num = f.getX().getNum();
		int denominator, denom;
		denominator = denom = f.getX().getDenom();
		int gcd = 1;
		for (int i = 2; i <= num && i <= denom; i++)
			if (num % i == 0 && denom % i == 0)
				gcd = i;
		numrator /= gcd;
		denominator /= gcd;
		o << "  The current Point X value has\n"
			"    Numerator : " << numrator << "\n"
			"    Denominator  : " << denominator << "\n";
		numrator = num = f.getY().getNum();
		denominator = denom = f.getY().getDenom();
		gcd = 1;
		for (int i = 2; i <= num && i <= denom; i++)
			if (num % i == 0 && denom % i == 0)
				gcd = i;
		numrator /= gcd;
		denominator /= gcd;
		o << "  The current Point Y value has\n"
			"    Numerator : " << numrator << "\n"
			"    Denominator  : " << denominator << "\n";
		return o;
	}
private:
	fractionBabakF fX;
	fractionBabakF fY;
};
#endif