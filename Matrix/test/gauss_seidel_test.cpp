#include <iostream>
#include "matrix.hpp"
#include "matrix_func.hpp"
#include "read_file.hpp"
#include "write_file.hpp"

void beforAction(Matrix* a1, Matrix* a2) {

	unsigned int M=0;
	unsigned int N=0;
	float eps;
	std::cout << " Enter Epsilon" << "\n";
	std::cout << "eps = ";
	std::cin >> eps ;    
        FileReader ra("./test/txt_files/a.txt");
	FileReader rb("./test/txt_files/gauss_seidel.txt");
        FileWriter wc("./test/txt_files/gauss_seidel_test.txt");
	M = ra.getnumrow();
	N = rb.getnumcolumn();

        Matrix a(M,M);
	a1 = new Matrix(M,M);
	a2 = new Matrix(M,N);

        ra.readmatrix(a1);
       	rb.readmatrix(a2);
}

void afterAction(Matrix* a1, Matrix* a2) {
	delete a1;
	delete a2;
}

void test1(const Matrix& t1, const Matrix& t2, Matrix& y)
{
	Matrix* a;
	Matrix* x;
	beforAction(a, b);

	Matrix r;
	Mult_Matrixt(a, x, r);
	assert(r == gout, "PASSSSSS")

	afterAction(a, b);
//	Mult_Matrixt(t1, t2, y);
}

int main()
{
//unsigned int M=0;
//unsigned int N=0;
//float eps;
//std::cout << " Enter Epsilon" << "\n";
//std::cout << "eps = ";
//std::cin >> eps ;    
//FileReader ra("./test/txt_files/a.txt"), rb("./test/txt_files/gauss_seidel.txt");
//FileWriter wc("./test/txt_files/gauss_seidel_test.txt");
//M = ra.getnumrow();
//N = rb.getnumcolumn();
//
//Matrix a(M,M);
//Matrix x(M,N);
//Matrix b_g_s(M,N);
//while(ra.readmatrix(a) && rb.readmatrix(x))
//{
//        test1(a,x,b_g_s);
//	Mult_Matrix(a, x, b_g_s);
//        wc.WriteMatrix(b_g_s);
//}

	return 0;
}
