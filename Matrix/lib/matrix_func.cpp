#include <iostream>
#include "matrix.hpp"
#include "read_file.hpp"
#include "write_file.hpp"
#include "matrix_func.hpp"
#include <cmath>

bool converge( const Matrix& x, const Matrix& y , float eps)
{
	float e = eps;
	float norm = 0;
	for (int i = 0; i < x.getnumofRows(); i++)
		norm += (x(i) - y(i))*(x(i) - y(i));
	return (sqrt(norm) > 0.00001);
}

void Gauss_Seidel_Method(const Matrix& a, const Matrix& b, Matrix& x, float eps)
{
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
}
void Jakob_Method(const Matrix& a, const Matrix& b, Matrix& x, float eps)
{
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
			//              std::cout << x(h) << "  " ;
		}
		//      std::cout << std::endl;
		//      std::cout << norm << "   "; 
		//      std::cout << "\n";
	} while ( norm > eps );
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
                        //              std::cout << y(i,j) << "  ";

                }
                //      std::cout << "\n";
        }

}

