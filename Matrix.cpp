/*
* Everything below does not work due to some template magic.
* It does not allow to link template declarations and definitions
* if they are not in the same file.
* So I moved everything from here to the header file.
*/
//#include <iostream>
//#include "Matrix.h"
//
//template <class _Item> Matrix<_Item>::Matrix(void) {};
//template <class _Item> Matrix<_Item>::Matrix(_Item** _matrix, size_t _cols, size_t _rows) : cols(_cols), rows(_rows) {
//	this->matrix = new _Item* [this->rows];
//	for (int i = 0; i < this->cols; i++) this->matrix[i] = new _Item[this->cols];
//	for (int i = 0; i < this->cols; i++)
//		for (int j = 0; j < this->rows; j++)
//		this->matrix[i][j] = _matrix[i][j];
//
//};
//template <class _Item> _Item Matrix<_Item>::Det(void) { return 0; };
//template <class _Item> void Matrix<_Item>::Print(void) {
//	for (int i = 0; i < this->rows; i++) {
//		for (int j = 0; j < this->cols; j++)
//			std::cout << this->matrix[i][j] << '\t';
//		std::cout << std::endl;
//	};
//
//	return;
//};
//
//template <class _Item> Matrix3x3<_Item>::Matrix3x3(void) : Matrix<_Item>() {};
//template <class _Item> Matrix3x3<_Item>::Matrix3x3(_Item** _matrix) : Matrix<_Item>(_matrix, 3, 3) {};
//template <class _Item> _Item Matrix3x3<_Item>::Det(void) {
//	return (
//		(this->matrix[0][0] * this->matrix[1][1] * this->matrix[2][2]) +
//		(this->matrix[0][1] * this->matrix[1][2] * this->matrix[2][0]) +
//		(this->matrix[1][0] * this->matrix[2][1] * this->matrix[0][2])
//		) - (
//			(this->matrix[0][2] * this->matrix[1][1] * this->matrix[2][0]) +
//			(this->matrix[2][1] * this->matrix[1][2] * this->matrix[0][0]) +
//			(this->matrix[1][0] * this->matrix[0][1] * this->matrix[2][2])
//			);
//}
//template <class _Item> _Item Matrix3x3<_Item>::Det1(_Item* _replace1) {
//	return (
//		(_replace1[0] * this->matrix[1][1] * this->matrix[2][2]) +
//		(this->matrix[0][1] * this->matrix[1][2] * _replace1[2]) +
//		(_replace1[1] * this->matrix[2][1] * this->matrix[0][2])
//		) - (
//			(this->matrix[0][2] * this->matrix[1][1] * _replace1[2]) +
//			(this->matrix[2][1] * this->matrix[1][2] * _replace1[0]) +
//			(_replace1[1] * this->matrix[0][1] * this->matrix[2][2])
//			);
//};
//template <class _Item> _Item Matrix3x3<_Item>::Det2(_Item* _replace2) {
//	return (
//		(this->matrix[0][0] * _replace2[1] * this->matrix[2][2]) +
//		(_replace2[0] * this->matrix[1][2] * this->matrix[2][0]) +
//		(this->matrix[1][0] * _replace2[2] * this->matrix[0][2])
//		) - (
//			(this->matrix[0][2] * _replace2[1] * this->matrix[2][0]) +
//			(_replace2[2] * this->matrix[1][2] * this->matrix[0][0]) +
//			(this->matrix[1][0] * _replace2[0] * this->matrix[2][2])
//			);
//}
//template <class _Item> _Item Matrix3x3<_Item>::Det3(_Item* _replace3) {
//	return (
//		(this->matrix[0][0] * this->matrix[1][1] * _replace3[2]) +
//		(this->matrix[0][1] * _replace3[1] * this->matrix[2][0]) +
//		(this->matrix[1][0] * this->matrix[2][1] * _replace3[0])
//		) - (
//			(_replace3[0] * this->matrix[1][1] * this->matrix[2][0]) +
//			(this->matrix[2][1] * _replace3[1] * this->matrix[0][0]) +
//			(this->matrix[1][0] * this->matrix[0][1] * _replace3[2])
//			);
//};
