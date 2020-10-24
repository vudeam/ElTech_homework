#include "Complex.h"

Complex::Complex(void) : Re(0), Im(0) {};
Complex::Complex(double _ReIm) : Re(_ReIm), Im(_ReIm) {};
Complex::Complex(double _Re, double _Im) : Re(_Re), Im(_Im) {};
Complex::Complex(Complex& _orig) : Re(_orig.Re), Im(_orig.Im) {};
Complex& Complex::operator = (const Complex& _right) {
	this->Re = _right.Re;
	this->Im = _right.Im;
	return *this;
}
Complex& Complex::operator + (const Complex& _right) {
	return *(new Complex(this->Re + _right.Re, this->Im + _right.Im));
}
Complex& Complex::operator - (const Complex& _right) {
	return *(new Complex(this->Re - _right.Re, this->Im - _right.Im));
}
Complex& Complex::operator * (const Complex& _right) {
	return
		*(new Complex(
			this->Re * _right.Re - this->Im * _right.Im,
			this->Re * _right.Im + this->Im * _right.Re
		));
}
Complex& Complex::operator / (const Complex& _right) {
	return
		*(new Complex(
			(this->Re * _right.Re + this->Im * _right.Im) / (_right.Re * _right.Re + _right.Im * _right.Im),
			(this->Im * _right.Re - this->Re * _right.Im) / (_right.Re * _right.Re + _right.Im * _right.Im)
		));
}
std::ostream& operator << (std::ostream& _ostr, const Complex& num) {
	_ostr << num.Re << '_' << num.Im << 'j';
	return _ostr;
}
