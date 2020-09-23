#include <iostream>
#include "Matrix.h"

int main(void) {
	double orig[3][3] = {
		{ 105, -28, -62 },
		{ -28, 83, -38 },
		{ -62, -38, 121 }
	};
	double** M_arr = new double* [3];
	FORi(0, 3) M_arr[i] = new double[3];
	FORi(0, 3)
		FORj(0, 3)
		M_arr[i][j] = orig[i][j];

	Matrix3x3 Mat(M_arr);
	Mat.Print();
	std::cout << "Det(A) = " << Mat.Det() << std::endl;

	return 0;
}
