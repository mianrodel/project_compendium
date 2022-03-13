#pragma once
#include "LinkedBag.h"
//template < class ItemType>
class term
{
private:
	int coeff;
	int expo;
public:
	term();
	int getCoeff()const;
	void setCoeff(int x);
	int getExpo()const;
	void setExpo(int x);
	void setCox(int coef, int exp);
	bool operator ==(const term& a) const;
	void operator <<(const term& a);
	bool operator <(const term& a) const;
	bool operator >(const term& a) const;
	void operator =(const term& a);

};
//#include "Terminos.cpp"
//#endif

//template < class ItemType>
term::term()
{
	coeff = 0;
	expo = 0;
}
//template < class ItemType>
int term::getCoeff() const
{
	return coeff;
}
//template < class ItemType>
void term::setCoeff(int x)
{
	coeff = x;
}
//template < class ItemType>
int term::getExpo() const
{
	return expo;
}
//template < class ItemType>
void term::setExpo(int x)
{
	expo = x;
}
//template < class ItemType>
void term::setCox(int coef, int exp)
{
	coeff = coef;
	expo = exp;
}
//template < class ItemType>
bool term::operator==(const term& a) const
{
	if (a.coeff == coeff && a.coeff == a.coeff)
		return true;
	else
		return false;
}
//template < class ItemType>
void term::operator <<(const term& a)
{
	cout << getCoeff() << "(x)^" << getExpo();
}
//template < class ItemType>
bool term::operator <(const term& a) const
{
	if (a.expo < expo)
		return true;
	else
		return false;
}
//template < class ItemType>
bool term::operator >(const term& a) const
{
	if (a.expo < expo)
		return true;
	else
		return false;
}
//template < class ItemType>
void term::operator =(const term& a)
{
	this->expo = a.getExpo();
	this->coeff = a.getCoeff();
}
