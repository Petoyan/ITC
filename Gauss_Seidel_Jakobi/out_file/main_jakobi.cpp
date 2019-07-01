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
	int count = 0;
	std::cout << " Enter Epsilon" << "\n";
	std::cout << "eps = ";
	std::cin >> eps ;    
        FileReader ra("./txt_files/a.txt"), rb("./txt_files/b.txt");
        FileWriter wc("./txt_files/jakobi.txt");
	M = ra.getnumrow();
	N = rb.getnumcolumn();
        Matrix a(M,M), b(M,N), x(M,N);
        while(ra.readmatrix(a) && rb.readmatrix(b))
        {
                if(!(Jakob_Method(a,b,x,eps)))
			++count;
                wc.WriteMatrix(x);
        }
	std::cout << "digits unsolved equation = " << count << "\n"; 
	return 0;
}
