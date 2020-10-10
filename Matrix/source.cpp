#include <iostream>
#include <vector>
#include <ctime>
#include "Matrix.h"

int main()
{
	Matrix m1(2, 3), m2(3, 2);
	clock_t t1, t2;
	t1 = clock();
	std::cout << m1 << std::endl << m2 << std::endl << m1 * m2 << std::endl;
	t2 = clock();
	std::cout << "Total time: " << double(t2 - t1) << std::endl;
	return 0;
}