#include <math.h>
#include "Complex.h"

Complex::Complex(void) : Re(0), Im(0) {};
Complex::Complex(double _ReIm) : Re(_ReIm), Im(_ReIm) {};
Complex::Complex(double _Re, double _Im) : Re(_Re), Im(_Im) {};
Complex::Complex(Complex& _orig) : Re(_orig.Re), Im(_orig.Im) {};
double Complex::Real(void) { return this->Re; }
double Complex::Imag(void) { return this->Im; }
double Complex::Abs(void) { return sqrt(this->Re*this->Re + this->Im*this->Im); }
Complex& Complex::operator = (const Complex& _right) {
	this->Re = _right.Re;
	this->Im = _right.Im;
	return *this;
}
Complex& Complex::operator + (const Complex& _right) const {
	return *(new Complex(this->Re + _right.Re, this->Im + _right.Im));
}
Complex& Complex::operator - (const Complex& _right) const {
	return *(new Complex(this->Re - _right.Re, this->Im - _right.Im));
}
Complex& Complex::operator * (const Complex& _right) const {
	return
		*(new Complex(
			this->Re * _right.Re - this->Im * _right.Im,
			this->Re * _right.Im + this->Im * _right.Re
		));
}
Complex& Complex::operator / (const Complex& _right) const {
	return
		*(new Complex(
			(this->Re * _right.Re + this->Im * _right.Im) / (_right.Re * _right.Re + _right.Im * _right.Im),
			(this->Im * _right.Re - this->Re * _right.Im) / (_right.Re * _right.Re + _right.Im * _right.Im)
		));
}
std::ostream& operator << (std::ostream& _ostr, const Complex& num) {
	_ostr << std::fixed << std::setprecision(5) << num.Re << (num.Im <= 0 ? '-' : '+') << fabs(num.Im) << 'j';
	return _ostr;
}
Complex& Complex::operator - () const {
	return
		*(new Complex(
			-this->Re,
			-this->Im
		));
}
Complex& Complex::Conj(void) const {
	return
		*(new Complex(
			this->Re,
			-this->Im
		));
}
