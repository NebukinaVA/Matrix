#pragma omp parallel for

#include <iostream>
#include <vector>

class Matrix
{
	std::vector<double> v;
	double *row;
public:
	Matrix(int s = 20)
	{
		m1.resize(s*s);
		row = v.data;
	}
	~Matrix()
	{
	}
	Matrix operator*(Matrix &mt)
	{
		double scal = 0;
		Matrix temp(mt.v.size());
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
					scal = scal + m[k][i] * mt.m[i][k];
				temp[i][j] = scal;
			}
		}
	}
};
