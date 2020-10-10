#pragma omp parallel for

#include <iostream>
#include <vector>
#include <ctime>

class Matrix
{
	std::vector<double> v;
	double *row;
	int size1; // strings
	int size2; // columns
public:
	Matrix(int s1 = 3, int s2 = 3)
	{
		srand(time(NULL));
		size1 = s1;
		size2 = s2;
		for (int i = 0; i < size1*size2; i++)
			v.push_back(rand() % 100);
		row = v.data();
	}
	~Matrix()
	{
	}

	Matrix operator*(const Matrix &mt)
	{
		if (size2 != mt.size1) throw "Can't multiply";
		double sum = 0;
		Matrix temp(size1, mt.size2);
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size1; j++)
			{
				for (int k = 0; k < mt.size1; k++)
				{
					sum = sum + *(row + i * size2 + k)**(mt.row + k * mt.size2 + j);
				}
				*(temp.row + i * size1 + j) = sum;
				sum = 0;
			}
		}
		return temp;
	}
	friend std::ostream& operator<<(std::ostream & out, const Matrix &m)
	{
		for (int i = 0; i < m.size1*m.size2; i += m.size2)
		{
			for (int j = 0; j < m.size2; j++)
				out << m.v[i + j] << ' ';
			out << std::endl;
		}
		return out;
	}
};