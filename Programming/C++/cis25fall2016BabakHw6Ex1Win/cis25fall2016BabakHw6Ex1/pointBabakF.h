/*
program name: pointBabakF.H
Discussion: Specification -- point Class
Writen by: Babak
Due daate: 2016/12/13
*/

#ifndef pointBabakF_H
#define pointBabakF_H
#include "fractionBabakF.h"


// Declarations
class pointBabakF {
public:
	pointBabakF() :fX(), fY() {};//default constructor,
	pointBabakF(int nx, int dx, int ny, int dy) : fX(nx, dx), fY(ny, dy) {};//copy contructor,
	~pointBabakF();//destructor

	fractionBabakF getX(void) const;

	fractionBabakF getY(void) const;

	void setX(int, int);
	void setY(int, int);
	void update(int, int, int, int);
	void update(int, fractionBabakF Y);
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
		int Xnum = f.getX().getNum();
		int Xdenom = f.getX().getDenom();
		int Ynum = f.getY().getNum();
		int Ydenom = f.getY().getDenom();
		cout <<
			"        " << Xnum << "   " << Ynum << " \n"
			"      ( - , - )\n"
			"        " << Xdenom << "   " << Ydenom << " " << endl;
		return o;
	}

private:
	fractionBabakF fX;
	fractionBabakF fY;
};
#endif