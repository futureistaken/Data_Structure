/*
program name: Shape.H
Discussion:   Specification -- Shape Class
Writen by:    Babak
Due daate:    2016/12/15
*/

#ifndef SHAPE_H
#define	SHAPE_H
#include <iostream>
#include "fractionBabakF.h"
using namespace std;

class Shape
{
public:
	virtual fractionBabakF computeArea(void) = 0;
	virtual fractionBabakF computePerimeter(void) = 0;
};
#endif
