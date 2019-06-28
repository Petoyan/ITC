#include <iostream>
#include <cassert>
#include "matrix.hpp"
#include "matrix_func.hpp"
#include "read_file.hpp"
#include "write_file.hpp"

void test1()
{
        unsigned int M=0;
        unsigned int N=0;
        FileReader ra("./txt_files/a.txt"), rb("./txt_files/gauss.txt");
        FileWriter wc("./txt_files/gauss_test_result.txt");
        M = ra.getnumrow();
        N = rb.getnumcolumn();
        Matrix a(M,M), b(M,N), x(M,N);
        while(ra.readmatrix(a) && rb.readmatrix(b))
        {
                Mult_Matrix(a, b, x);
                wc.WriteMatrix(x);
        }
}

void test2()
{
        unsigned int M=0;
        unsigned int N=0;
	float eps;
	std::cout << " Enter Epsilon" << "\n";
        std::cout << "eps = ";
        std::cin >> eps ;
	int count = 0;
	int count1 = 0;
        FileReader ra("./txt_files/gauss_test_result.txt"), rb("./txt_files/b.txt");
        //FileWriter wc("./txt_files/gauss_test_result.txt");
        M = ra.getnumrow();
        N = rb.getnumcolumn();
        Matrix a(M,M), b(M,N);
        while(ra.readmatrix(a) && rb.readmatrix(b))
        {
               count++;
               if(!Matrix_Equal(a, b, eps))
               {
                       count1++;
               }
        }
        std::cout << "Integration test for Gauss Seidel method" << "\n";
        std::cout << "Count matrix " << count << "\n";
        std::cout << "Count wrong matrix " << count1 << "\n";
}


int main()
{
	test1();
	test2();

	return 0;
}
