#include <iostream>
#include <vector>

template <class T>
class Matrix
{
	std::vector<vector<T>> m;
	int size;
public:
	Matrix(int s = 20)
	{
		size = s;
	}
	~Matrix()
	{
	}
	Matrix<T> operator*(Matrix<T> &mt)
	{
		if (size != mt.size) throw "error";
		T scal = 0;
		Matrix<T> temp(size);
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
