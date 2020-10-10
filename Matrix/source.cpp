#pragma omp parallel for

#include <iostream>
#include <vector>
#include <ctime>

class Matrix
{
	std::vector<double> v;
	double *row;
	int size;
public:
	Matrix(int s = 3)
	{
		srand(time(NULL));
		size = s;
		for (int i = 0; i < size*size; i++)
			v.push_back(rand() % 100);
		row = v.data();
	}
	~Matrix()
	{
	}
	Matrix operator*(Matrix &mt)
	{
		double sum;
		Matrix temp(mt.size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sum = 0;
				for (int k = 0; k < size; k++)
				{
					sum = sum + *(row + i * size + k)**(mt.row + k * size + j);
					*(temp.row + i * size + j) = sum;
				}
			}
		}
		return temp;
	}
	friend std::ostream& operator<<(std::ostream & out, const Matrix &m)
	{
		for (int i = 0; i < m.size*m.size; i += m.size)
		{
			for (int j = 0; j < m.size; j++)
				out << m.v[i + j] << ' ';
			out << std::endl;
		}
		return out;
	}
};

int main()
{
	Matrix m1, m2, m3;
	clock_t t1, t2;
	t1 = clock();
	m3 = m1 * m2;
	t2 = clock();
	std::cout << m1 << std::endl << m2 << std::endl << m3 << std::endl;
	std::cout << "Total time: " << double(t2 - t1) << std::endl;
	return 0;
}