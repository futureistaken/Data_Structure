/*
program name: circleBabakF.H
Discussion:   Specification -- Circle Class
Writen by:    Babak
Due daate:    2016/12/15
*/

#ifndef circleBabakF_H
#define circleBabakF_H
#include "pointBabakF.h"
#include "fractionBabakF.h"
#include "Shape.h"

using namespace std;

class circleBabakF : public Shape
{
public:
	circleBabakF() : cPtr(new pointBabakF()), rPtr(new fractionBabakF()){};
	circleBabakF(int xn,int xd,int yn,int yd, int rn, int rd) : cPtr(new pointBabakF(xn,xd,yn,yd)), rPtr(new fractionBabakF(rn,rd)) {};
	void update(int,int,int,int,int,int);
	int position(const circleBabakF* C) const;
	fractionBabakF getCenter(const fractionBabakF* C) const;
	void moveByIntH(int,const circleBabakF* C)const ;
	void moveByIntY(int, const circleBabakF* C)const;
	void moveByFractionH(fractionBabakF& f, const circleBabakF* c) const;
	void moveByFractionY(fractionBabakF& f, const circleBabakF* c) const;
	void printArea(void) const;
	void printPerimeter(void) const;
	fractionBabakF computeArea();
	fractionBabakF computePerimeter();
	~circleBabakF();
	void print(void) const;
private:
	pointBabakF* cPtr;
	fractionBabakF* rPtr;
};


#endif
