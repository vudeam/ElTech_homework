#include <iostream>
#include "Matrix.h"

Matrix::Matrix(void) {};
Matrix::Matrix(double** _matrix, size_t _cols, size_t _rows) : cols(_cols), rows(_rows) {
	this->matrix = new double* [this->rows];
	for (int i = 0; i < this->cols; i++) this->matrix[i] = new double[this->cols];
	for (int i = 0; i < this->cols; i++)
		for (int j = 0; j < this->rows; j++)
		this->matrix[i][j] = _matrix[i][j];

};
double Matrix::Det(void) { return 0; };
void Matrix::Print(void) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++)
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
double Matrix3x3::Det1(double* _replace1) {
	return (
		(_replace1[0] * this->matrix[1][1] * this->matrix[2][2]) +
		(this->matrix[0][1] * this->matrix[1][2] * _replace1[2]) +
		(_replace1[1] * this->matrix[2][1] * this->matrix[0][2])
		) - (
			(this->matrix[0][2] * this->matrix[1][1] * _replace1[2]) +
			(this->matrix[2][1] * this->matrix[1][2] * _replace1[0]) +
			(_replace1[1] * this->matrix[0][1] * this->matrix[2][2])
			);
};
double Matrix3x3::Det2(double* _replace2) {
	return (
		(this->matrix[0][0] * _replace2[1] * this->matrix[2][2]) +
		(_replace2[0] * this->matrix[1][2] * this->matrix[2][0]) +
		(this->matrix[1][0] * _replace2[2] * this->matrix[0][2])
		) - (
			(this->matrix[0][2] * _replace2[1] * this->matrix[2][0]) +
			(_replace2[2] * this->matrix[1][2] * this->matrix[0][0]) +
			(this->matrix[1][0] * _replace2[0] * this->matrix[2][2])
			);
}
double Matrix3x3::Det3(double* _replace3) {
	return (
		(this->matrix[0][0] * this->matrix[1][1] * _replace3[2]) +
		(this->matrix[0][1] * _replace3[1] * this->matrix[2][0]) +
		(this->matrix[1][0] * this->matrix[2][1] * _replace3[0])
		) - (
			(_replace3[0] * this->matrix[1][1] * this->matrix[2][0]) +
			(this->matrix[2][1] * _replace3[1] * this->matrix[0][0]) +
			(this->matrix[1][0] * this->matrix[0][1] * _replace3[2])
			);
};
