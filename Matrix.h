#pragma once
#define FORi(start, stop) for (int i = start; i < stop; i += 1)
#define FORj(start, stop) for (int j = start; j < stop; j += 1)
class Matrix {
protected:
	size_t rows;
	size_t cols;
	double** matrix;

public:
	Matrix(void);
	Matrix(double**, size_t, size_t);
	double Det(void);
	void Print(void);
};

class Matrix3x3 : public Matrix {
public:
	Matrix3x3(void);
	Matrix3x3(double**);
	double Det(void);
	double Det1(double*);
	double Det2(double*);
	double Det3(double*);
};
