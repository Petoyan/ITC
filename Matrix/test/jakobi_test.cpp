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
        FileReader ra("./txt_files/a.txt"), rb("./txt_files/b.txt");
        FileWriter wc("./txt_files/jakob.txt");
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
