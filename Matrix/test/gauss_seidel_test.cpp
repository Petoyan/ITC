#include <iostream>
#include <cassert>
#include "matrix.hpp"
#include "matrix_func.hpp"
#include "read_file.hpp"
#include "write_file.hpp"

/*void beforAction(Matrix* a1, Matrix* a2, Matrix* a3) {

	unsigned int M=0;
	unsigned int N=0;
	float eps;
	
        FileReader ra("./txt_files/a.txt");
	FileReader rb("./txt_files/b.txt");
	FileReader rx("./txt_files/gauss_seidel.txt");
        FileWriter wc("./txt_files/gauss_seidel_test.txt");
	M = ra.getnumrow();
	N = rb.getnumcolumn();

	a1 = new Matrix(M,M);
	a2 = new Matrix(M,N);
	a3 = new Matrix(M,N);

        ra.readmatrix(a1);
       	rx.readmatrix(a2);
	rb.readmatrix(a3);
}

void afterAction(Matrix* a1, Matrix* a2) {
	delete a1;
	delete a2;
	delete a3;
}

void test1(float eps)
{
	Matrix* a;
	Matrix* b;
	Matrix* x;
	beforAction();

	Matrix r(x.getnumofRows(),x.getnumofColumns());
	Mult_Matrix(a, x, r);
	assert(Matrix_Equal(r,b,eps));

	afterAction(a, b);
}
*/
int main()
{
	float eps;
	std::cout << " Enter Epsilon" << "\n";
	std::cout << "eps = ";
	std::cin >> eps ;    
	//test1(eps);

	return 0;
}
