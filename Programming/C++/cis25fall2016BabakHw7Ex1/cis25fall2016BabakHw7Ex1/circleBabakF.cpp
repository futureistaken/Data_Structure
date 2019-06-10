/*
program name: circleBabakF.cpp
Discussion:   Implementation -- circle Class
Writen by:    Babak
Due date:     2016/12/15
*/

#include "circleBabakF.h"
#include "fractionBabakF.h"
#include "pointBabakF.h"

void circleBabakF::update(int xn, int xd, int yn, int yd, int rn, int rd)
{
	cPtr->update(xn, xd, yn, yd);
	rPtr->update(rn, rd);
}
int circleBabakF::position(const circleBabakF* C)const {
	fractionBabakF* R0 = new fractionBabakF(*(rPtr));
	fractionBabakF* R1 = new fractionBabakF(*(C->rPtr));
	fractionBabakF* X0 = new fractionBabakF((cPtr->getX()));
	fractionBabakF* X1 = new fractionBabakF((C->cPtr->getX()));
	fractionBabakF* Y0 = new fractionBabakF((cPtr->getY()));
	fractionBabakF* Y1 = new fractionBabakF((C->cPtr->getY()));
	fractionBabakF* D = new fractionBabakF();
	(*D) = ((((*X1) - (*X0)) ^ 2) + (((*Y1) - *(Y0)) ^ 2));
	if ((*R0) >= (*R1))
	{
		if (((*D).getNum()) == 0 && ((*R0) == ((*R1))))//circles are inside of each other with the same center and with a same radius.
		{
			delete R0;
			delete R1;
			delete X0;
			delete X1;
			delete Y0;
			delete Y1;
			delete D;
			return 0;
		}
		else if ((((*R0) + (*R1)) ^ 2) <= (*D))//circles are outside and they could touch each others curve.
		{
			delete R0;
			delete R1;
			delete X0;
			delete X1;
			delete Y0;
			delete Y1;
			delete D;
			return 1;
		}
		else if ((((*R0) + (*R1)) ^ 2) > (*D))//circles are inside of each other with the same center.
		{
			if ((*D) == 0 && (*R0) > 0 && (*R1) > 0)
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 6;//circles are inside of each other with same center.
			}
			else if ((*D) + ((*R1) ^ 2) <= ((*R0) ^ 2))//circles are inside of each other with diferent center.
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 2;
			}
			else if ((*D) < ((*R0) ^ 2))//circles are overlaping ceach other and the center of the small circle is iside the big cicel.
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 3;
			}
			else if ((*D) >= ((*R1) ^ 2))//circles are overlaping ceach other.
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 4;
			}
			else
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 5;
			}
		}
	}
	else
	{
		if (((*D).getNum()) == 0 && ((*R0) == ((*R1))))//circles are inside of each other with the same center and with a same size.
		{
			delete R0;
			delete R1;
			delete X0;
			delete X1;
			delete Y0;
			delete Y1;
			delete D;
			return 0;
		}
		else if ((((*R1) + (*R0)) ^ 2) <= (*D))//circles are outside and they could touch each others curve.
		{
			delete R0;
			delete R1;
			delete X0;
			delete X1;
			delete Y0;
			delete Y1;
			delete D;
			return 1;
		}
		else if ((((*R1) + (*R0)) ^ 2) > (*D))//circles are inside of each other with the same center.
		{
			if ((*D) == 0 && (*R0) > 0 && (*R1) > 0)//circles are inside of each other with same center.
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 6;
			}
			else if ((*D) + ((*R0) ^ 2) <= ((*R1) ^ 2))//circles are inside of each other with diferent center.
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 2;
			}
			else if ((*D) <= ((*R1) ^ 2))//circles are overlaping ceach other and the center of the small circle is iside the big cicel.
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 3;
			}
			else if ((*D) >= ((*R1) ^ 2))//circles are overlaping ceach other.
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 4;
			}
			else
			{
				delete R0;
				delete R1;
				delete X0;
				delete X1;
				delete Y0;
				delete Y1;
				delete D;
				return 5;
			}
		}
	}
}
fractionBabakF circleBabakF::getCenter(const fractionBabakF * C) const
{
	return fractionBabakF();
}
void circleBabakF::moveByIntH(int f, const circleBabakF * c) const
{
	cPtr->setX((((*c).cPtr->getX().getNum()) + (f * (*c).cPtr->getX().getDenom())), ((*c).cPtr->getX().getDenom()));
}
void circleBabakF::moveByIntY(int f, const circleBabakF * c) const
{
	cPtr->setY(((*c).cPtr->getY()) + f);
}
void circleBabakF::moveByFractionH(fractionBabakF & f, const circleBabakF * c) const
{
	cPtr->setX(((*c).cPtr->getX()) + f);
}
void circleBabakF::moveByFractionY(fractionBabakF & f, const circleBabakF * c) const
{
	cPtr->setY(((*c).cPtr->getY()) + f);
}
void circleBabakF::printArea(void) const
{
	if ((((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() >> 999 || (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() > 999)
	{
		cout << "\n"
			"          " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() << " \n"
			"  Area :  --- \n"
			"          " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() << endl;
	}
	else if ((((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() > 99 || (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() > 99)
	{
		cout << "\n"
			"           " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() << " \n"
			"  Area :   -- \n"
			"           " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() << endl;
	}
	else
	{
		cout << "\n"
			"          " << (*rPtr).getNum() << " \n"
			"  Area :  - \n"
			"          " << (*rPtr).getDenom() << endl;
	}
}
void circleBabakF::printPerimeter(void) const
{
	if ((((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() >> 999 || (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() > 999)
	{
		cout << "\n"
			"          " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() << " \n"
			"  Perimeter :  --- \n"
			"          " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() << endl;
	}
	else if ((((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() > 99 || (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() > 99)
	{
		cout << "\n"
			"           " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getNum() << " \n"
			"  Perimeter :   -- \n"
			"           " << (((fractionBabakF(157, 50)) ^ 2) * (*rPtr)).getDenom() << endl;
	}
	else
	{
		cout << "\n"
			"          " << (*rPtr).getNum() << " \n"
			"  Perimeter :  - \n"
			"          " << (*rPtr).getDenom() << endl;
	}
}
fractionBabakF circleBabakF::computeArea()
{
	return fractionBabakF(((fractionBabakF(157, 50))^2) * (*rPtr));
}
fractionBabakF circleBabakF::computePerimeter()
{
	return fractionBabakF((fractionBabakF(157, 50) * (*rPtr)) * 2);
}
circleBabakF::~circleBabakF()
{
	delete cPtr;
	delete rPtr;
}
void circleBabakF::print() const {
	cout <<
		"             " << (*cPtr).getX().getNum() << "   " << (*cPtr).getY().getNum() << " \n"
		"  Center : ( - , - )\n"
		"             " << (*cPtr).getX().getDenom() << "   " << (*cPtr).getY().getDenom() << " " << endl;
	cout << "\n"
		"             " << (*rPtr).getNum() << " \n"
		"  Radius : ( - )\n"
		"             " << (*rPtr).getDenom() << endl;
}