﻿#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "Matrix.h"
#include "Complex.h"

#define FORi(start, stop) for (int i = start; i < stop; i++)
#define FORj(start, stop) for (int j = start; j < stop; j++)

void HW1(void);

const char* fillLine = "+-----------+------+------+------+------+------+------+";
double** M_R = nullptr; // Матрица сопротивлений
double** M_G = nullptr; // Матрица проводимостей

int main(void) {
	//HW1();

	/*Complex num1(13, 1);
	Complex num2(7, -6);

	std::cout << num1 << " + " << num2 << " : " << num1 + num2 << std::endl;
	std::cout << num1 << " - " << num2 << " : " << num1 - num2 << std::endl;
	std::cout << num1 << " * " << num2 << " : " << num1 * num2 << std::endl;
	std::cout << num1 << " / " << num2 << " : " << num1 / num2 << std::endl;*/


	Complex num1(1, 0);
	Complex num2(1, 0);
	Complex num3(1, 0);
	Complex num4(0);
	Complex num5(18, 84.446);
	Complex num6(0, -92.362);
	Complex num7(0, -62.121);
	Complex num8(-18, -84.446);
	Complex num9(0);

	Complex** M_I__full = nullptr;
	M_I__full = new Complex* [3];
	FORi(0, 3) M_I__full[i] = new Complex[3];
	M_I__full[0][0] = num1;
	M_I__full[0][1] = num2;
	M_I__full[0][2] = num3;
	M_I__full[1][0] = num4;
	M_I__full[1][1] = num5;
	M_I__full[1][2] = num6;
	M_I__full[2][0] = num7;
	M_I__full[2][1] = num8;
	M_I__full[2][2] = num9;

	Complex E1_(0);
	Complex E2_(0, 48.79);
	Complex E3_(-13.635, 16.25);
	Complex* M_E_ = new Complex[3] { E1_, E2_, E3_ };

	Matrix3x3<Complex> M_I_(M_I__full);
	std::cout << "I1_ = " << M_I_.Det1(M_E_) / M_I_.Det() << std::endl;


	std::cin.clear(); std::cin.ignore(std::cin.rdbuf()->in_avail()); _flushall();
	std::cout << std::endl << "[Enter]";
	std::cin.get();

	return 0;
}

void HW1(void) {
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

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	// input data
	double R1, R2, R3, R4, R5, R6;
	double E1, E2, E3, E4, E5, E6;

	// output data
	double I1, I2, I3, I4, I5, I6;

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

	// Метод контурных токов
	double I11, I22, I33;
	M_R = new double* [3];
	FORi(0, 3) M_R[i] = new double[3];
	M_R[0][0] = R1 + R2 + R4;
	M_R[0][1] = -R2;
	M_R[0][2] = -R4;
	M_R[1][0] = -R2;
	M_R[1][1] = R2 + R3 + R5;
	M_R[1][2] = -R5;
	M_R[2][0] = -R4;
	M_R[2][1] = -R5;
	M_R[2][2] = R4 + R5 + R6;

	double* arr_E1 = new double[3];    // столбец ЭДС
	arr_E1[0] = E1 - E2 - E4;
	arr_E1[1] = E2 - E3 - E5;
	arr_E1[2] = E4 + E5 - E6;
	
	Matrix3x3<double> Matrix_R(M_R);
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
	std::cout << std::right << std::setw(6) << std::fixed << std::setprecision(3) << I1 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I2 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I3 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I4 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I5 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I6 << '|' << std::endl;
	
	delete[] arr_E1;
	delete[] M_R;
	/*------------------------------Конец метода контурных токов------------------------------*/


	// Метод узловых потенциалов
	double phi1, phi2, phi3;
	M_G = new double* [3];
	FORi(0, 3) M_G[i] = new double[3];
	M_G[0][0] = (1. / R1) + (1. / R4) + (1. / R6);
	M_G[0][1] = -1. / R1;
	M_G[0][2] = -1. / R6;
	M_G[1][0] = -1. / R1;
	M_G[1][1] = (1. / R1) + (1. / R2) + (1. / R3);
	M_G[1][2] = -1. / R3;
	M_G[2][0] = -1. / R6;
	M_G[2][1] = -1. / R3;
	M_G[2][2] = (1. / R3) + (1. / R5) + (1. / R6);
	
	double* arr_E2 = new double[3];
	arr_E2[0] = -(E1 / R1) - (E4 / R4) - (E6 / R6);
	arr_E2[1] = (E1 / R1) + (E2 / R2) + (E3 / R3);
	arr_E2[2] = -(E3 / R3) + (E5 / R5) + (E6 / R6);

	Matrix3x3<double> Matrix_G(M_G);
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
	std::cout << std::right << std::setw(6) << std::fixed << std::setprecision(3) << I1 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I2 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I3 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I4 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I5 << '|' <<
		std::right << std::setw(6) << std::fixed << std::setprecision(3) << I6 << '|' << std::endl;
	std::cout << fillLine;
	
	delete[] arr_E2;
	delete[] M_G;
	/*-------------------------Конец метода узловых потенциалов-------------------------*/

	std::cout << std::endl << "Баланс мощностей: " <<
		(I1 * E1) + (I2 * E2) + (I3 * E3) + (I4 * E4) + (I5 * E5) + (I6 * E6) << " Вт = " <<
		(R1 * I1 * I1) + (R2 * I2 * I2) + (R3 * I3 * I3) + (R4 * I4 * I4) + (R5 * I5 * I5) + (R6 * I6 * I6) << " Вт" << std::endl;


	// Метод эквивалентного двухполюсника
	double Udc, Uxx, Ia, Ib, Rin;

	Rin = 1. / ((1. / (R4 + ((R2 * R5) / (R2 + R3 + R5)))) + (1. / (R6 + ((R3 * R5) / (R2 + R3 + R5))))) + ((R2*R3) / (R2+R3+R5));
	Udc = ( (-E2 * (1. / (R2+R3))) + (E3 * (1. / (R2+R3))) + (E4 * (1. / (R4+R6))) + (-E5 * (1./R5)) + (-E6 * (1. / (R4+R6))) ) /
		( (1. / (R4+R6)) + (1. / R5) + (1. / (R2+R3)) );
	Ia = (E4 - E6 - Udc) / (R4 + R6);
	Ib = (E2 - E3 + Udc) / (R2 + R3);
	Uxx = R2*Ib + R4*Ia + E1 - E2 - E4;
	std::cout << std::endl << "Метод эквивалентного двухполюсника: I1 = " << Uxx / (Rin + R1) << 'A' << std::endl;
	/*-------------------------Конец метода эквивалентного двухполюсника-------------------------*/

	return;
}
