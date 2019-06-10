/*
program name: fractionBabakF.H
Discussion:   Specification -- Fraction Class
Writen by:    Babak
Due daate:    2016/12/15
*/

#ifndef fractionBabakF_H
#define fractionBabakF_H
#include <iostream>
using namespace std;

class fractionBabakF
{
public:
	// A constructor is
	//	 - A member function
	//	 - Having the same name as the class name
	//	 - Not to return anything
	fractionBabakF();// Default constructor is a one that has no arguments ****
	fractionBabakF(int, int);
	fractionBabakF(int);//Convert constractor
	fractionBabakF(const fractionBabakF&);//Copy Constroctor *****
	~fractionBabakF();//Destructor		
	//opratation 
	int getNum(void) const;
	int getDenom(void) const;
	void setNum(int n);
	void setDenom(int n);
	void update(int n, int d);
	void print(void) const;
	int* extractUncommonDigit(void) const;

	fractionBabakF add(int) const;
	fractionBabakF add(fractionBabakF*) const;
	fractionBabakF add(const fractionBabakF& f) const;
	fractionBabakF add(int, const fractionBabakF&);

	fractionBabakF Multiplying(int f) const;
	fractionBabakF Multiplying(fractionBabakF * f) const;
	fractionBabakF Multiplying(const fractionBabakF & f) const;
	fractionBabakF Multiplying(int f1, const fractionBabakF & f2);

	fractionBabakF subract(int f) const;
	fractionBabakF subract(fractionBabakF * f) const;
	fractionBabakF subract(const fractionBabakF & f) const;
	fractionBabakF subract(int f1, const fractionBabakF & f2);

	fractionBabakF Dividing(int f) const;
	fractionBabakF Dividing(fractionBabakF * f) const;
	fractionBabakF Dividing(const fractionBabakF & f) const;
	fractionBabakF Dividing(int f1, const fractionBabakF & f2);
	fractionBabakF sqrt(int, int)const;

	//oprator function
	fractionBabakF operator+(const fractionBabakF&) const;
	fractionBabakF operator+(int) const;
	fractionBabakF operator-(const fractionBabakF&) const;
	fractionBabakF operator*(const fractionBabakF & f) const;
	fractionBabakF operator*(int) const;
	fractionBabakF operator^(int) const;
	bool operator<=(const fractionBabakF & f) const;
	bool fractionBabakF::operator>=(const fractionBabakF & f) const;
	bool fractionBabakF::operator==(const fractionBabakF & f) const;
	bool fractionBabakF::operator>(const fractionBabakF & f) const;
	bool fractionBabakF::operator<(const fractionBabakF & f) const;

	fractionBabakF operator/(const fractionBabakF & f) const;


	fractionBabakF operator=(const fractionBabakF&);

	//friend is a modifier 
	friend ostream& operator<<(ostream& o, const fractionBabakF& f) {
		if (f.num > 9999)
		{
			o <<
				"    " << f.num << " \n"
				"      ----- \n"
				"      " << f.denom << endl;

		}
		else if (f.denom > 9999)
		{
			o <<
				"     " << f.num << " \n"
				"     ----- \n"
				"   " << f.denom << endl;

		}
		else if (f.num > 999)
		{
			o <<
				"    " << f.num << " \n"
				"    ---- \n"
				"     " << f.denom << endl;

		}
		else if (f.denom > 999)
		{
			o <<
				"    " << f.num << " \n"
				"    ---- \n"
				"   " << f.denom << endl;

		}
		else if (f.num > 99)
		{
			o <<
				"   " << f.num << " \n"
				"   --- \n"
				"    " << f.denom << endl;

		}
		else if (f.denom > 99)
		{
			o <<
				"    " <<f. num << " \n"
				"   --- \n"
				"   " << f.denom << endl;
		}
		else if (f.num > 9 || f.denom > 9)
		{
			o <<
				"   " << f.num << " \n"
				"   -- \n"
				"   " << f.denom << endl;
		}
		else
		{
			o <<
				"   " << f.num << " \n"
				"   - \n"
				"   " << f.denom << endl;
		}
		return o;
	}
private:
	int num;
	int denom;

};
#endif