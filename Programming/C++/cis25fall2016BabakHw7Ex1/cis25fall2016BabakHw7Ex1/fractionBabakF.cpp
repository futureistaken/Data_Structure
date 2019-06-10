/*
program name: fractionBabakF.cpp
Discussion:   Implementation -- Fraction Class
Writen by:    Babak
Due date:     2016/12/15
*/
#include "fractionBabakF.h"
#include <iostream>
using namespace std;

fractionBabakF::fractionBabakF()
{
	num = 0;
	denom = 1;
}
fractionBabakF::fractionBabakF(int n, int d) {
	int gcd = 1;
	for (int i = 2; i <= n && i <= d; i++)
		if (n % i == 0 && d % i == 0)
			gcd = i;
	n /= gcd;
	d /= gcd;
	num = n;
	denom = d;
}
fractionBabakF::fractionBabakF(int number)
{
	num = number;
	denom = 1;
}
fractionBabakF::fractionBabakF(const fractionBabakF& that) {
	num = that.num;
	denom = that.denom;
}

int fractionBabakF::getNum() const {
	return num;
}
int fractionBabakF::getDenom() const {
	return denom;
}
void fractionBabakF::setNum(int n) {
	num = n;
}
void fractionBabakF::setDenom(int d) {
	denom = d;
}
void fractionBabakF::update(int n, int d)
{
	int gcd = 1;
	for (int i = 2; i <= n && i <= d; i++)
		if (n % i == 0 && d % i == 0)
			gcd = i;
	n /= gcd;
	d /= gcd;
	num = n;
	denom = d;
}

fractionBabakF fractionBabakF::add(int f) const
{
	return fractionBabakF((f * denom) + num, denom);
}
fractionBabakF fractionBabakF::add(fractionBabakF * f) const
{
	return (num * (*f).denom + denom * (*f).num, denom + (*f).denom);
}
fractionBabakF fractionBabakF::add(const fractionBabakF& f) const
{

	return (num * f.denom + denom * f.num, denom + f.denom);

}
fractionBabakF fractionBabakF::add(int f1, const fractionBabakF& f2)
{
	return fractionBabakF(f1 * (f2.denom) + f2.num, f2.denom);
}

fractionBabakF fractionBabakF::subract(int f) const
{
	return ((f * denom) - num);
}
fractionBabakF fractionBabakF::subract(fractionBabakF * f) const
{
	return (num * (*f).denom - denom * (*f).num, denom - (*f).denom);
}
fractionBabakF fractionBabakF::subract(const fractionBabakF& f) const
{

	return (num * f.denom - denom * f.num, denom - f.denom);

}
fractionBabakF fractionBabakF::subract(int f1, const fractionBabakF& f2)
{
	return fractionBabakF(f1 * (f2.denom) - f2.num, f2.denom);
}

fractionBabakF fractionBabakF::Multiplying(int f) const
{
	return (f * num, denom);
}
fractionBabakF fractionBabakF::Multiplying(fractionBabakF* f) const
{
	return (num * f->num, denom * f->denom);
}
fractionBabakF fractionBabakF::Multiplying(const fractionBabakF& f) const
{

	return (num * f.num, denom * f.denom);

}
fractionBabakF fractionBabakF::Multiplying(int f1, const fractionBabakF& f2)
{
	return fractionBabakF(f1 * (f2.num), f2.denom);
}


fractionBabakF fractionBabakF::Dividing(int f) const
{
	if (num != 0)
		return (denom * f, num);
	else
		cout << "\nYour Fraction has 0 on the numrator, Please update the numerator, and Re-try\n";
}
fractionBabakF fractionBabakF::Dividing(fractionBabakF* f) const
{
	if (f->num != 0)
		return (num * f->denom, denom * f->num);
	else
		cout << "\nYour Fraction has 0 on the numrator, Please update the numerator, and Re-try\n";

}
fractionBabakF fractionBabakF::Dividing(const fractionBabakF& f) const
{
	if (f.num != 0)
		return (num * f.denom, denom * f.num);
	else
		cout << "\nYour Fraction has 0 on the numrator, Please update the numerator, and Re-try\n";

}
fractionBabakF fractionBabakF::Dividing(int f1, const fractionBabakF& f2)
{
	if (f2.num != 0)
		return fractionBabakF(f1 * (f2.denom), f2.num);
	else
		cout << "\nYour Fraction has 0 on the numrator, Please update the numerator, and Re-try\n";

}

//Operators
fractionBabakF fractionBabakF::operator^(const int f) const
{

	int Num = num;
	int Denom = denom;
	if (num < 0)
	{
		Num = -Num;
	}
	for (int i = 0; i < f - 1; i++)
	{
		Num *= Num;
		Denom *= Denom;
	}
	return fractionBabakF(Num, Denom);
}
fractionBabakF fractionBabakF::sqrt(int num, int denom) const
{
	int Num, Denom;
	double temp;
	double sqrtNum = num / 2;
	double sqrtDenom = denom / 2;
	do
	{
		temp = sqrtNum;
		sqrtNum = (temp + (num / temp)) / 2;
	} while ((temp - sqrtNum) != 0);
	do
	{
		temp = sqrtDenom;
		sqrtDenom = (temp + (denom / temp)) / 2;
	} while ((temp - sqrtDenom) != 0);
	Denom = sqrtNum * 1000;
	return fractionBabakF(Num, Denom);
}
bool fractionBabakF::operator<=(const fractionBabakF & f) const
{
	double leftResult = num / denom;
	double rightResult = f.num / f.denom;

	if (leftResult <= rightResult)
		return (true);

	else
		return (false);

}
bool fractionBabakF::operator>=(const fractionBabakF & f) const
{
	double leftResult = num / denom;
	double rightResult = f.num / f.denom;

	if (leftResult >= rightResult)
		return (true);

	else
		return (false);
}
bool fractionBabakF::operator==(const fractionBabakF & f) const
{
	double leftResult = num / denom;
	double rightResult = f.num / f.denom;

	if (leftResult == rightResult)
		return (true);

	else
		return (false);
}
bool fractionBabakF::operator>(const fractionBabakF & f) const
{
	double leftResult = num / denom;
	double rightResult = f.num / f.denom;

	if (leftResult > rightResult)
		return (true);

	else
		return (false);
}
bool fractionBabakF::operator<(const fractionBabakF & f) const
{
	double leftResult = num / denom;
	double rightResult = f.num / f.denom;

	if (leftResult < rightResult)
		return (true);

	else
		return (false);
}
fractionBabakF fractionBabakF::operator+(const fractionBabakF& f) const
{

	return fractionBabakF(num * f.denom + denom * f.num, denom * f.denom);

}
fractionBabakF fractionBabakF::operator+(int f) const
{
	return fractionBabakF(num + f * denom, denom);
}
fractionBabakF fractionBabakF::operator-(const fractionBabakF& f) const
{
	if (f.num < 0)
	{
		return fractionBabakF(num * f.denom + denom * f.num, denom * f.denom);
	}
	else
	{
		return fractionBabakF(num * f.denom - denom * f.num, denom * f.denom);
	}

}
fractionBabakF fractionBabakF::operator*(const fractionBabakF& f) const
{

	return fractionBabakF(num * f.num, denom * f.denom);

}
fractionBabakF fractionBabakF::operator*(int f) const
{

	return fractionBabakF(num * f, denom);

}
fractionBabakF fractionBabakF::operator/(const fractionBabakF& f) const
{
	if (f.num !=0)
	return fractionBabakF(num * f.denom, denom * f.num);
	else
		cout << "\nYour Fraction has 0 on the numrator, Please update the numerator, and Re-try\n";
}

void fractionBabakF::print() const
{
	if (num > 99)
	{
		cout << "\n"
			"   " << num << " \n"
			"   --- \n"
			"    " << denom << endl;

	}
	else if (denom > 99)
	{
		cout << "\n"
			"    " << num << " \n"
			"   --- \n"
			"   " << denom << endl;
	}
	else if (num > 9 || denom > 9)
	{
		cout << "\n"
			"   " << num << " \n"
			"   -- \n"
			"   " << denom << endl;
	}
	else
	{
		cout << "\n"
			"   " << num << " \n"
			"   - \n"
			"   " << denom << endl;

	}

}
int* fractionBabakF::extractUncommonDigit() const
{

	return nullptr;
}

fractionBabakF fractionBabakF::operator=(const fractionBabakF& f)
{
	num = f.num;
	denom = f.denom;
	return fractionBabakF(num, denom);
}
fractionBabakF::~fractionBabakF()
{
}
