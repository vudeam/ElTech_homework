#pragma once
#define FORi (start, stop) for (int i = start; i < stop; i++)
#define FORj (start, stop) for (int j = start; j < stop; j++)
double reverse_sum(double x1, double x2, double x3) {
	return (1. / x1) + (1. / x2) + (1. / x3);
}
