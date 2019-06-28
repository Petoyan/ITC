#include <iostream>
#include "matrix.hpp"
#include "matrix_func.hpp"
#include "read_file.hpp"
#include "write_file.hpp"

int main()
{
	unsigned int M=0;
	unsigned int N=0;
        FileReader ra("./txt_files/a.txt"), rb("./txt_files/b.txt");
        FileWriter wc("./txt_files/gauss.txt");
	M = ra.getnumrow();
	N = ra.getnumcolumn();
        Matrix a(M,N), b(M,1), x(N,1);
        while(ra.readmatrix(a) && rb.readmatrix(b))
        {
                Gauss_Method(a,b,x);
                wc.WriteMatrix(x);
        }

	return 0;
}
