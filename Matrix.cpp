#include "Matrix.h"
#include <iostream>

Matrix::Matrix(void) {};
Matrix::Matrix(double** _matrix, size_t _cols, size_t _rows) : cols(_cols), rows(_rows) {
	this->matrix = new double* [this->rows];
	FORi(0, this->cols) this->matrix[i] = new double[this->cols];
	FORi(0, this->cols)
		FORj(0, this->rows)
		this->matrix[i][j] = _matrix[i][j];

};
double Matrix::Det(void) { return 0; };
void Matrix::Print(void) {
	FORi(0, this->rows) {
		FORj(0, this->cols)
			std::cout << this->matrix[i][j] << '\t';
		std::cout << std::endl;
	};

	return;
};

Matrix3x3::Matrix3x3(void) : Matrix() {};
Matrix3x3::Matrix3x3(double** _matrix) : Matrix(_matrix, 3, 3) {};
double Matrix3x3::Det(void) {
	return (
		(this->matrix[0][0] * this->matrix[1][1] * this->matrix[2][2]) +
		(this->matrix[0][1] * this->matrix[1][2] * this->matrix[2][0]) +
		(this->matrix[1][0] * this->matrix[2][1] * this->matrix[0][2])
		) - (
			(this->matrix[0][2] * this->matrix[1][1] * this->matrix[2][0]) +
			(this->matrix[2][1] * this->matrix[1][2] * this->matrix[0][0]) +
			(this->matrix[1][0] * this->matrix[0][1] * this->matrix[2][2])
			);
}
