#include <iostream>
#include <iomanip>
#include <Windows.h>
#define _USE_MATH_DEFINES
const double PI = std::acos(-1);
#include <cmath>

#include "Matrix.h"
#include "Complex.h"

#define FORi(start, stop) for (int i = start; i < stop; i++)
#define FORj(start, stop) for (int j = start; j < stop; j++)

void HW1(void);
void HW2(void);

const char* fillLine = "+-----------+------+------+------+------+------+------+";
double**   M_R = nullptr;  // Матрица сопротивлений
double**   M_G = nullptr;  // Матрица проводимостей

Complex** M_I_ = nullptr; // Матрица коэффициентов при комплексных токах
Complex** M_E_ = nullptr; // Столбец комплексов ЭДС
//Complex** c;

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// HW1(); //<---------------------------- расскомментируйте, чтобы делать первую работу
	HW2(); //<---------------------------- расскомментируйте, чтобы делать вторую работу

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

void HW2(void) {
	double f, omega = 0;
	double* R    = new double[3];
	double* Em   = new double[6];
	double* phiE = new double[6];
	double* L    = new double[6];
	double* C    = new double[6];
	Complex* E_ = new Complex[6];
	Complex* Z_ = new Complex[3];
	Complex I1_, I2_, I3_;

	/*
	//Вариант 87
	Em[0] = 30;
	Em[1] = 0;
	Em[2] = 69;
	Em[3] = 0;
	Em[4] = 0;
	Em[5] = 0;
	phiE[0] = 130;
	phiE[1] = 0;
	phiE[2] = 270;
	phiE[3] = 0;
	phiE[4] = 0;
	phiE[5] = 0;
	R[0] = 0;
	R[1] = 18;
	R[2] = 0;
	L[0] = 0;
	L[1] = 0;
	L[2] = .35;
	L[3] = 0;
	L[4] = .32;
	L[5] = 0;
	C[0] = 61.e-6;
	C[1] = 0;
	C[2] = 0;
	C[3] = 0;
	C[4] = 0;
	C[5] = 0;
	f = 42;
	*/
	
	FORi(0, 6) {
		std::cout << "Em" << i + 1 << '=';
		std::cin >> Em[i];
	}
	FORi(0, 6) {
		std::cout << "phi" << i + 1 << '=';
		std::cin >> phiE[i];
	}
	FORi(0, 3) {
		std::cout << "R" << i + 1 << '=';
		std::cin >> R[i];
	}
	FORi(0, 6) {
		std::cout << "L" << i + 1 << '=';
		std::cin >> L[i];
	}
	FORi(0, 6) {
		std::cout << "C" << i + 1 << '=';
		std::cin >> C[i];
		C[i] = C[i] * 1e-6;
	}
	std::cout << "f=";
	std::cin >> f;
	
	omega = 2. * PI * f;
	
	std::cout << "######################## 0. Предварительные расчёты ########################" << std::endl;
	std::cout << "Комплексы ЭДС:" << std::endl;
	FORi(0, 6) {
		E_[i] = Complex(
			((Em[i]/sqrt(2.))*cos(phiE[i]*(PI/180.))),
			((Em[i]/sqrt(2.))*sin(phiE[i]*(PI/180.)))
		);
		std::cout << "E_" << i + 1 << " = " << E_[i] << std::endl;
	}
	std::cout << "Комплексы сопротивлений ветвей:" << std::endl;
	double XL = 0, XC = 0;
	FORi(0, 3) {
		XL = L[i] == 0 ? L[i] : omega*L[i];
		XL += L[i + 3] == 0 ? L[i + 3] : omega * L[i + 3];
		XC = C[i] == 0 ? C[i] : 1. / (omega * C[i]);
		XC += C[i + 3] == 0 ? C[i + 3] : 1. / (omega * C[i + 3]);
		Z_[i] = Complex(
			R[i],
			XL - XC
		);
		std::cout << "Z_" << i + 1 << " = " << Z_[i] << std::endl;
	}

	//------------------------- Решение системы из пункта 1 (для проверки значений токов)
	M_I_ = new Complex*[3];
	FORi(0, 3) M_I_[i] = new Complex[3];
	/*Complex c0(1, 0);
	Complex c1(1, 0);
	Complex c2(1, 0);
	Complex c3(R[0],
		-(C[3] == 0 ? C[3] : 1. / (omega * C[3])) + (omega * L[3]) - (C[0] == 0 ? C[0] : 1. / (omega * C[0])) + (omega * L[0]));
	Complex c4(-R[1],
		-(omega * L[1]) + (C[1] == 0 ? C[1] : 1. / (omega * C[1])) - (omega * L[4]) + (C[4] == 0 ? C[4] : 1. / (omega * C[4])));
	Complex c5(0);
	Complex c6(0);
	Complex c7(R[1],
		(omega* L[1]) - (C[1] == 0 ? C[1] : 1. / (omega * C[1])) + (omega * L[4]) - (C[4] == 0 ? C[4] : 1. / (omega * C[4])));
	Complex c8(-R[2],
		-(omega * L[2]) + (C[2] == 0 ? C[2] : 1. / (omega * C[2])) - (omega * L[5]) + (C[5] == 0 ? C[5] : 1. / (omega * C[5])));*/
	/*c = new Complex * [3];
	FORi(0, 3) c[i] = new Complex[3];*/
	M_I_[0][0] = Complex(
		1,
		0
	);
	M_I_[0][1] = Complex(
		1,
		0
	);
	M_I_[0][2] = Complex(1,
		0
	);
	M_I_[1][0] = Complex(
		R[0],
		-(C[3] == 0 ? C[3] : 1. / (omega * C[3])) + (omega * L[3]) - (C[0] == 0 ? C[0] : 1. / (omega * C[0])) + (omega * L[0])
	);
	M_I_[1][1] = Complex(
		-R[1],
		-(omega * L[1]) + (C[1] == 0 ? C[1] : 1. / (omega * C[1])) - (omega * L[4]) + (C[4] == 0 ? C[4] : 1. / (omega * C[4]))
	);
	M_I_[1][2] = Complex(
		0
	);
	M_I_[2][0] = Complex(
		0
	);
	M_I_[2][1] = Complex(
		R[1],
		(omega * L[1]) - (C[1] == 0 ? C[1] : 1. / (omega * C[1])) + (omega * L[4]) - (C[4] == 0 ? C[4] : 1. / (omega * C[4]))
	);
	M_I_[2][2] = Complex(
		-R[2],
		-(omega * L[2]) + (C[2] == 0 ? C[2] : 1. / (omega * C[2])) - (omega * L[5]) + (C[5] == 0 ? C[5] : 1. / (omega * C[5]))
	);

	/*M_I_[0][0] = new Complex(
		1,
		0
	);
	M_I_[0][1] = new Complex(
		1,
		0
	);
	M_I_[0][2] = new Complex(
		1,
		0
	);
	M_I_[1][0] = new Complex(
		R[0],
		-(C[3] == 0 ? C[3] : 1./(omega*C[3])) + (omega*L[3]) - (C[0] == 0 ? C[0] : 1./(omega*C[0])) + (omega*L[0])
	);
	M_I_[1][1] = new Complex(
		-R[1],
		-(omega*L[1]) + (C[1] == 0 ? C[1] : 1./(omega*C[1])) - (omega*L[4]) + (C[4] == 0 ? C[4] : 1./(omega*C[4]))
	);
	M_I_[1][2] = new Complex(
		0
	);
	M_I_[2][0] = new Complex(
		0
	);
	M_I_[2][1] = new Complex(
		R[1],
		(omega*L[1]) - (C[1] == 0 ? C[1] : 1./(omega*C[1])) + (omega*L[4]) - (C[4] == 0 ? C[4] : 1./(omega*C[4]))
	);
	M_I_[2][2] = new Complex(
		-R[2],
		-(omega*L[2]) + (C[2] == 0 ? C[2] : 1./(omega*C[2])) - (omega*L[5]) + (C[5] == 0 ? C[5] : 1./(omega*C[5]))
	);*/
	/*
	M_I_[0][0] = new Complex(
		1,
		0
	);
	M_I_[0][1] = new Complex(
		1,
		0
	);
	M_I_[0][2] = new Complex(
		1,
		0
	);
	M_I_[1][0] = new Complex(
		R[0],
		-(C[3] == 0 ? C[3] : 1./(omega*C[3])) + (omega*L[3]) - (C[0] == 0 ? C[0] : 1./(omega*C[0])) + (omega*L[0])
	);
	M_I_[1][1] = new Complex(
		-R[1],
		-(omega*L[1]) + (C[1] == 0 ? C[1] : 1./(omega*C[1])) - (omega*L[4]) + (C[4] == 0 ? C[4] : 1./(omega*C[4]))
	);
	M_I_[1][2] = new Complex(
		0
	);
	M_I_[2][0] = new Complex(
		0
	);
	M_I_[2][1] = new Complex(
		R[1],
		(omega*L[1]) - (C[1] == 0 ? C[1] : 1./(omega*C[1])) + (omega*L[4]) - (C[4] == 0 ? C[4] : 1./(omega*C[4]))
	);
	M_I_[2][2] = new Complex(
		-R[2],
		-(omega*L[2]) + (C[2] == 0 ? C[2] : 1./(omega*C[2])) - (omega*L[5]) + (C[5] == 0 ? C[5] : 1./(omega*C[5]))
	);
	*/

	/*M_E_ = new Complex*[3];
	M_E_[0] = new Complex(
		0
	);
	M_E_[1] = new Complex(
		-*(E_[1]) - *(E_[4]) + *(E_[3]) + *(E_[0])
	);
	M_E_[2] = new Complex(
		-*(E_[2]) - *(E_[5]) + *(E_[4]) + *(E_[1])
	);*/
	/*Complex E1_(0);
	Complex E2_(-E_[1] - E_[4] + E_[3] + E_[0]);
	Complex E3_(-E_[2] - E_[5] + E_[4] + E_[1]);*/

	Complex* Matrix_E_ = new Complex[3] {
		(0),
		(-E_[1] - E_[4] + E_[3] + E_[0]),
		(-E_[2] - E_[5] + E_[4] + E_[1])
	};
	/*FORi(0, 3) {
		FORj(0, 3) {
			std::cout << *(M_I_[i][j]) << '\t';
		}
		std::cout << std::endl;
	}*/
	std::cout << std::endl
		<< "######################## 1. Решение системы б) ########################"
		<< std::endl;
	Matrix3x3<Complex> Matrix_I_(M_I_);
	std::cout << "Матрица коэффициентов перед комплексными токами имеет вид:" << std::endl;
	Matrix_I_.Print();
	std::cout << "Полученные значения комплексных токов из подпункта б) :" << std::endl;
	std::cout << "I1_ = " << Matrix_I_.Det1(Matrix_E_) / Matrix_I_.Det() << std::endl;
	std::cout << "I2_ = " << Matrix_I_.Det2(Matrix_E_) / Matrix_I_.Det() << std::endl;
	std::cout << "I3_ = " << Matrix_I_.Det3(Matrix_E_) / Matrix_I_.Det() << std::endl;

	//------------------------- 2. Определение токов в ветвях
	std::cout << std::endl
		<< "######################## 2. Определение токов в ветвях методом двух узлов ########################"
		<< std::endl;
	Complex Uab_(
		( ((E_[0] + E_[3]) / Z_[0]) + ((E_[1] + E_[4]) / Z_[1]) + ((E_[2] + E_[5]) / Z_[2]) ) /
		( (Complex(1, 0) / Z_[0]) + (Complex(1, 0) / Z_[1]) + (Complex(1, 0) / Z_[2]) )
	);
	std::cout << "Межузловое напряжение:" << std::endl;
	std::cout << "Uab_ = " << Uab_ << std::endl;
	std::cout << "Найденные токи:" << std::endl;
	I1_ = (E_[0] + E_[3] - Uab_) / Z_[0];
	I2_ = (E_[1] + E_[4] - Uab_) / Z_[1];
	I3_ = (E_[2] + E_[5] - Uab_) / Z_[2];
	std::cout << "I1_ = " << I1_ << std::endl;
	std::cout << "I2_ = " << I2_ << std::endl;
	std::cout << "I1_ = " << I3_ << std::endl;
	
	//------------------------- 3. Определение мощности
	std::cout << std::endl
		<< "######################## 3. Определение показаний ваттметра ########################"
		<< std::endl;
	std::cout << "Мощность с помощью тока и напряжения на ваттметре:" << std::endl
		<< (Uab_ * I1_.Conj()).Real() << " Вт" << std::endl;
	std::cout << "Мощность по формуле UIcos:" << std::endl
		<< Uab_.Abs() * I1_.Abs() * cos(atan(Uab_.Imag() / Uab_.Real()) - atan(I1_.Imag() / I1_.Real()))
		<< " Вт" << std::endl;

	//------------------------- 5. Мгновенное значение тока i1
	std::cout << std::endl
		<< "######################## 5. Запись выражения мгновенного значения тока i1(t) ########################"
		<< std::endl;
	std::cout << "Выражение для мгновенного значения тока i1 имеет вид:" << std::endl
		<< "i(t) = Im*sin(omega*t + psiI)" << std::endl << "где" << std::endl
		<< "Im (амплитуда) = " << I1_.Abs() * sqrt(2.) << " A " << std::endl
		<< "omega (угловая частота) = 2*pi*f = " << 2 * PI * f << std::endl
		<< "psiI (начальная фаза I1_) = " << atan(I1_.Imag() / I1_.Real()) << " рад" << std::endl
		<< "В итоге получаем выражение для тока i1(t):" << std::endl
		<< "i1(t) = " << I1_.Abs() * sqrt(2) << "*sin(omega*t + "
		<< (I1_.Real() < 0 ? PI + atan(I1_.Imag() / I1_.Real()) : atan(I1_.Imag() / I1_.Real()))
		<< ')' << std::endl;

	delete[] Z_;
	delete[] E_;
	delete[] C;
	delete[] L;
	delete[] phiE;
	delete[] Em;
	delete[] R;

	return;
}
