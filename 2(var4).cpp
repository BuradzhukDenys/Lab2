#include <iostream>

using namespace std;

template<typename T>
class Matrix
{
private:
	T** data;
	int size;
public:
	Matrix() : size(3), data(nullptr)
	{
		data = new T * [size];
		for (int i = 0; i < size; i++)
		{
			data[i] = new T[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				data[i][j] = 0;
			}
		}
	}

	Matrix(T value, int n) : size(n), data(nullptr)
	{
		if (size > 0)
		{
			data = new T * [size];
			for (int i = 0; i < size; i++)
			{
				data[i] = new T[size];
			}

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					data[i][j] = value;
				}
			}
		}
	}

	Matrix(const Matrix<T>& other) : size(other.size), data(nullptr)
	{
		if (size > 0)
		{
			size = other.size;
			data = new T * [size];
			for (int i = 0; i < size; i++)
			{
				data[i] = new T[size];
			}

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					data[i][j] = other.data[i][j];
				}
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}

	Matrix<T>& operator=(const Matrix<T>& other)
	{
		if (this != &other)
		{
			for (int i = 0; i < size; i++)
			{
				delete[] data[i];
			}
			delete[] data;

			size = other.size;
			data = new T * [size];
			for (int i = 0; i < size; i++)
			{
				data[i] = new T[size];
			}

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					data[i][j] = other.data[i][j];
				}
			}
		}

		return *this;
	}

	Matrix<T> operator+(const Matrix<T>& other) const
	{
		Matrix<T> result(0, size);
		if (size != other.size)
		{
			cout << "Matrices must be of the same size to add\n";
		}
		else {
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					result[i][j] = data[i][j] + other.data[i][j];
				}
			}
		}

		return result;
	}

	Matrix<T> operator-(const Matrix<T>& other) const
	{
		Matrix<T> result(0, size);
		if (size != other.size)
		{
			cout << "Matrices must be of the same size to subtract\n";
		}
		else {
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					result[i][j] = data[i][j] - other.data[i][j];
				}
			}
		}

		return result;
	}

	Matrix<T> operator*(const Matrix<T>& other) const
	{
		Matrix<T> result(0, size);
		if (size != other.size)
		{
			cout << "Matrices must be of the same size to multiply\n";
		}
		else {
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					result[i][j] = data[i][j] * other.data[i][j];
				}
			}
		}

		return result;
	}

	T* operator[](int i) { return data[i]; }
	const T* operator[](int i) const { return data[i]; }

	double norm() const
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sum += data[i][j] * data[i][j];
			}
		}
		return sqrt(sum);
	}

	void print() const
	{
		cout << "Matrix size of " << size << "x" << size << ": \n";
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << data[i][j] << "\t";
			}
			cout << endl;
		}
	}

	int Size() const { return size; }
};

template <typename T>
void squareMatrix(Matrix<T>* matrices, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Matrix " << i + 1 << ":\n";
		matrices[i].print();
		cout << "Matrix in square: " << matrices[i].norm() << endl;
		cout << "------------------------\n";
	}
}

int main()
{
	Matrix<int> m1;
	Matrix<int> m2(5, 4);

	cout << "Matrix 1:\n";
	m1.print();
	cout << "Matrix 2:\n";
	m2.print();

	Matrix<int> m3(m2);
	cout << "Matrix 3:\n";
	m3.print();

	Matrix<int> m4;
	Matrix<int> m5;
	Matrix<int> m6;

	m1 = m2;
	m1.print();

	m4 = m2 + m3;
	m5 = m2 - m3;
	m6 = m2 * m3;

	cout << "Matrix 4:\n";
	m4.print();
	cout << "Matrix 5:\n";
	m5.print();
	cout << "Matrix 6:\n";
	m6.print();

	const int size = 3;
	Matrix<double> matrices[size] = {
		Matrix<double>(1.5, 4),
		Matrix<double>(5.31, 2),
		Matrix<double>(5.8, 3)
	};

	squareMatrix<double>(matrices, size);
}