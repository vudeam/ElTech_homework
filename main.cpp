#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Matrix.h"

/* INPUT TEMPLATE
+-----------+------+------+------+------+------+------+
|Метод      |I1    |I2    |I3    |I4    |I5    |I6    |
+-----------+------+------+------+------+------+------+
|М. К. Т.   |      |      |      |      |      |      |
+-----------+------+------+------+------+------+------+
|М. У. П.   |      |      |      |      |      |      |
+-----------+------+------+------+------+------+------+


+-----------+------+------+------+------+------+------+
|Величина   |R1    |R2    |R3    |R4    |R5    |R6    |
+-----------+------+------+------+------+------+------+
|Значение   |      |      |      |      |      |      |
+-----------+------+------+------+------+------+------+


+-----------+------+------+------+------+------+------+
|Величина   |E1    |E2    |E3    |E4    |E5    |E6    |
+-----------+------+------+------+------+------+------+
|Значение   |      |      |      |      |      |      |
+-----------+------+------+------+------+------+------+
*/

double reverse_sum(double, double, double);

const char* fillLine = "+-----------+------+------+------+------+------+------+";
double** M_R = nullptr;
double** M_G = nullptr;

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*double orig[3][3] = {
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
	double* repl = new double[3];
	repl[0] = -1;
	repl[1] = 0;
	repl[2] = 14;
	std::cout << "Det1(-1, 0, 14) = " << Mat.Det1(repl) << std::endl;
	std::cout << "Det2(-1, 0, 14) = " << Mat.Det2(repl) << std::endl;
	std::cout << "Det3(-1, 0, 14) = " << Mat.Det3(repl) << std::endl;*/
	
	// input data
	double R1, R2, R3, R4, R5, R6;
	double E1, E2, E3, E4, E5, E6;

	// output data
	double I1, I2, I3, I4, I5, I6;


	/*int inputCount = 0;
	// << std::fixed << std::setprecision(1) << (double)_stud.AverageScore(j + 1)
	FORi(0, 6) {
		std::cout << fillLine << std::endl;
		std::cout << '|' << std::left << std::setw(11) << "Величина" << '|';
		FORj(0, 6) std::cout << 'R' << j + 1 << "    |";
		std::cout << fillLine << std::endl;
		std::cout << '|' << std::left << std::setw(11) << "Значение" << '|';
		FORj(0, 6) std::cout << ((j + 1) > inputCount ? "      |" : std::fixed << std::setprecision(3) << );
	}*/
	std::cout << "R1=";
	std::cin >> R1;
	std::cout << "R2=";
	std::cin >> R2;
	std::cout << "R3=";
	std::cin >> R3;
	std::cout << "R4=";
	std::cin >> R4;
	std::cout << "R5=";
	std::cin >> R5;
	std::cout << "R6=";
	std::cin >> R6;
	std::cout << std::endl << "E1=";
	std::cin >> E1;
	std::cout << "E2=";
	std::cin >> E2;
	std::cout << "E3=";
	std::cin >> E3;
	std::cout << "E4=";
	std::cin >> E4;
	std::cout << "E5=";
	std::cin >> E5;
	std::cout << "E6=";
	std::cin >> E6;
	std::cout << std::endl << std::endl;

	/*R1 = 17;
	R2 = 28;
	R3 = 1;
	R4 = 29;
	R5 = 98;
	R6 = 47;
	E1 = 19;
	E3 = 18;
	E2 = E4 = E5 = E6 = 0;*/

	// solution
	double I11, I22, I33;
	double orig[3][3] = {
		{ R1+R2+R4, -R2, -R4 },
		{ -R2, R2+R3+R5, -R5 },
		{ -R4, -R5, R4+R5+R6 }
	};
	double** M_R = new double* [3];
	FORi(0, 3) M_R[i] = new double[3];
	FORi(0, 3)
		FORj(0, 3)
		M_R[i][j] = orig[i][j];

	double* arr_E1 = new double[3];
	arr_E1[0] = E1 - E2 - E4;
	arr_E1[1] = E2 - E3 - E5;
	arr_E1[2] = E4 + E5 - E6;
	
	Matrix3x3 Matrix_R(M_R);
	I11 = Matrix_R.Det1(arr_E1) / Matrix_R.Det();
	I22 = Matrix_R.Det2(arr_E1) / Matrix_R.Det();
	I33 = Matrix_R.Det3(arr_E1) / Matrix_R.Det();
	I1 = I11;
	I2 = I22 - I11;
	I3 = -I22;
	I4 = -I11 + I33;
	I5 = -I22 + I33;
	I6 = -I33;
	std::cout << fillLine << std::endl;
	std::cout << '|' << std::left << std::setw(11) << "Метод" << '|';
	FORj(0, 6) std::cout << 'I' << j + 1 << "    |";
	std::cout << std::endl << fillLine << std::endl;
	std::cout << '|' << std::left << std::setw(11) << "М. К. Т." << '|';
	std::cout << std::setw(6) << std::fixed << std::setprecision(3) << I1 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I2 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I3 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I4 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I5 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I6 << '|' << std::endl;


	//delete[] M_arr;
	// delete[] repl;



	// М.У.П.
	double phi1, phi2, phi3;
	double orig2[3][3] = {
		{ reverse_sum(R1, R4, R6), -(1. / R1), -(1. / R6) },
		{ -(1. / R1), reverse_sum(R1, R2, R3), -(1. / R3) },
		{ -(1. / R6), -(1. / R3), reverse_sum(R3, R5, R6) }
	};
	FORi(0, 3)
		FORj(0, 3)
		M_R[i][j] = orig2[i][j];
	double* arr_E2 = new double[3];
	arr_E2[0] = -(E1 / R1) - (E4 / R4) - (E6 / R6);
	arr_E2[1] = (E1 / R1) + (E2 / R2) + (E3 / R3);
	arr_E2[2] = -(E3 / R3) + (E5 / R5) + (E6 / R6);

	Matrix3x3 Matrix_G(M_R);

	phi1 = Matrix_G.Det1(arr_E2) / Matrix_G.Det();
	phi2 = Matrix_G.Det2(arr_E2) / Matrix_G.Det();
	phi3 = Matrix_G.Det3(arr_E2) / Matrix_G.Det();
	I1 = (phi1 - phi2 + E1) / R1;
	I3 = (phi3 - phi2 + E3) / R3;
	I6 = (phi1 - phi3 + E6) / R6;
	I2 = - I1 - I3;
	I4 = - I1 - I6;
	I5 = I3 - I6;
	std::cout << fillLine << std::endl;
	std::cout << '|' << std::left << std::setw(11) << "М. У. П." << '|';
	std::cout << std::setw(6) << std::fixed << std::setprecision(3) << I1 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I2 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I3 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I4 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I5 << '|' <<
		std::setw(6) << std::fixed << std::setprecision(3) << I6 << '|' << std::endl;
	std::cout << fillLine;

	std::cin.clear(); std::cin.ignore(std::cin.rdbuf()->in_avail()); _flushall();
	std::cout << std::endl << "[Enter]";
	std::cin.get();

	return 0;
}

double reverse_sum(double x1, double x2, double x3) {
	return (1. / x1) + (1. / x2) + (1. / x3);
}
