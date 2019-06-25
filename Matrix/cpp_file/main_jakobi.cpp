#include <iostream>
#include "matrix.hpp"
#include "matrix_func.hpp"
#include "read_file.hpp"
#include "write_file.hpp"

int main()
{
	unsigned int M=0;
	unsigned int N=0;
	float  eps;
	std::cout << " Enter Epsilon" << "\n";
	std::cout << "eps = ";
	std::cin >> eps ;    
        FileReader ra("./cpp_file/txt_files/a.txt"), rb("./cpp_file/txt_files/b.txt");
        FileWriter wc("./cpp_file/txt_files/jakobi.txt");
	M = ra.getnumrow();
	N = rb.getnumcolumn();
        Matrix a(M,M), b(M,N), x(M,N);
        while(ra.readmatrix(a) && rb.readmatrix(b))
        {
                Jakob_Method(a,b,x,eps);
                wc.WriteMatrix(x);
        }

	return 0;
}
