#include <iostream>
#pragma once
class Complex {
private:
	double Re;
	double Im;

public:
	Complex(void);
	Complex(double);
	Complex(double, double);
	Complex(Complex&);
	Complex& operator = (const Complex&);
	Complex& operator + (const Complex&);
	Complex& operator - (const Complex&);
	Complex& operator * (const Complex&);
	Complex& operator / (const Complex&);
	friend std::ostream& operator << (std::ostream&, const Complex&);
};

std::ostream& operator << (std::ostream&, const Complex&);
