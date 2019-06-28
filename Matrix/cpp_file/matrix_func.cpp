#include <iostream>
#include "matrix.hpp"
#include "read_file.hpp"
#include "write_file.hpp"
#include "matrix_func.hpp"
#include <cmath>

bool chack_matrix(const Matrix& a)
{
        if(a.getnumofRows() == a.getnumofColumns()){
                return true;
        }else{
                return false;
             }
}

bool converge( const Matrix& x, const Matrix& y , float eps)
{
	float e = eps;
	float norm = 0;
	for (int i = 0; i < x.getnumofRows(); i++)
		norm += (x(i) - y(i))*(x(i) - y(i));
	return (sqrt(norm) > e);
}

void Gauss_Seidel_Method(const Matrix& a, const Matrix& b, Matrix& x, float eps)
{
	if(chack_matrix(a)){
	Matrix y(x.getnumofRows(),x.getnumofColumns());
	int n = a.getnumofRows();
	do
	{
		for (int i = 0; i < n; i++)
		{
			y(i) = x(i);
		}
		for (int i = 0; i < n; i++)
		{
			float var = 0;
			for (int j = 0; j < i; j++)
				var += (a(i,j) * x(j));
			for (int j = i + 1; j < n; j++)
				var += (a(i,j) * y(j));
			x(i) = (b(i) - var) / a(i,i);
		}
	}while(converge(x,y,eps));
	}else{
		std::cout<< "this matrix can not solved" << "\n";
	}
}

bool chack(const Matrix& a)
{
	for (int i = 0; i < a.getnumofRows(); ++i)
	{
		float x=0;
		for (int j = 0; j < a.getnumofColumns(); ++j)
		{
			x += a(i,j);
		}
		if(std::fabs(a(i,i)) < std::fabs(x-a(i,i)))
		{
			return false;
		}
	}
	return true;
}

void swap(Matrix& m, Matrix& b, int i)
{
	int n = m.getnumofRows();
	float maxEl = std::fabs(m(i,i));
	int maxRow = i;
	for (int k=i+1; k<n; k++){
		if (abs(m(k,i)) > maxEl){
			maxEl = std::fabs(m(k,i));
			maxRow = k;
		}
	}
	for (int k=i; k<n;k++) {
		float tmp = m(maxRow,k);
		m(maxRow,k) = m(i,k);
		m(i,k) = tmp;
	}
	float btmp = b(maxRow);
	b(maxRow) = b(i);
	b(i) = btmp;
}

void elemination(Matrix& m, Matrix& b, int i)
{
	int n = m.getnumofRows();
	float t;
	for(int k = i + 1; k < n; ++k) {
		t = m(k, i) / m(i, i);
		for(int j = 0; j < n; ++j) {
			m(k, j) = m(k, j) - (t * m(i, j));
		}
		b(k) = b(k) - (t * b(i));
	}

}

void backward(Matrix& m, Matrix& b, Matrix& x)
{
	int num_row = m.getnumofRows();
	int num_col = m.getnumofColumns();
	for(int i=num_col; i < num_row; i++)
	{
		if(b(i) != 0)
		{
			std::cout << "this matrix can not solved " << "\n";
			return;
		}
	}
	if(m((num_row-1), (num_row-1)) != 0)
	{
		int n = m.getnumofRows();
		for(int i = n - 1; i >= 0; --i) 
		{
			float d = 0;
			for(int k = i; k < n; ++k)
			{
				float s = m(i, k) * x(k);
				d = d + s;
			}
			x(i) = (b(i) - d)/(m(i,i));
		}
	}
	else
	{
		std::cout << "this matrix can not solved " << "\n";
	}
}

void Gauss_Method(Matrix& m, Matrix& b, Matrix& x)
{
	int n = m.getnumofRows();
	for(int i = 0; i < x.getnumofRows(); ++i) {
		x(i) = 0;
	}
	for(int i = 0; i < n; ++i) {
		swap(m,b,i);
		elemination(m,b,i);
	}
	backward(m,b,x);
}

void Jakob_Method(const Matrix& a, const Matrix& b, Matrix& x, float eps)
{
	if(chack_matrix(a) && chack(a)){
		float norm;
		Matrix y(x.getnumofRows(),x.getnumofColumns());
		int N = a.getnumofRows();
		do {
			for (int i = 0; i < N; i++) {
				y(i) = b(i);
				for (int g = 0; g < N; g++) {
					if (i != g)
						y(i) -= a(i,g) * x(g);
				}
				y(i) /= a(i,i);
			}
			norm = std::fabs(x(0) - y(0));
			for (int h = 0; h < N; h++) {
				if (std::fabs(x(h) - y(h)) > norm)
					norm = std::fabs(x(h) - y(h));
				x(h) = y(h);
			}
		} while ( norm > eps );
	}
	else
	{

		std::cout << "this matrix can not solved " << "\n";
	}
}
void Mult_Matrix(const Matrix& t1, const Matrix& t2, Matrix& y)
{
	for(int i = 0; i < t1.getnumofRows(); i++){
		for(int j = 0; j < t2.getnumofColumns(); j++){
			float s = 0;
			for(int k = 0; k < t1.getnumofColumns(); k++){
				s += t1(i,k) * t2(k,j);
			}
			y(i,j)=s;
		}
	}

}

bool Matrix_Equal(const Matrix& a, const Matrix& b, float eps)
{
	for(int i = 0; i < a.getnumofRows(); i++)
	{
		for(int j = 0; j < a.getnumofColumns(); j++)
		{
			float e = eps;
			float x = 0;
			x = std::fabs(a(i,0) - b(i,0));
			x =round(x*(1/e))/(1/e);
			if(x > e)
			{
				return false;
				break;
			}

		}
		return true;
	}
}
