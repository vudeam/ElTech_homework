#include <iostream>
#include <iomanip>
#pragma once
struct Complex {
private:
	double Re;
	double Im;

public:
	Complex(void);
	Complex(double);
	Complex(double, double);
	Complex(Complex&);
	double Real(void);
	double Imag(void);
	double Abs(void);
	Complex& operator = (const Complex&);
	Complex& operator + (const Complex&) const;
	Complex& operator - (const Complex&) const;
	Complex& operator * (const Complex&) const;
	Complex& operator / (const Complex&) const;
	friend std::ostream& operator << (std::ostream&, const Complex&);
	Complex& operator - () const;
	Complex& Conj(void) const;
};

std::ostream& operator << (std::ostream&, const Complex&);
