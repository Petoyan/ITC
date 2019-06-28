#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

int z=1;
void Input(unsigned int& M, unsigned int& N, unsigned int& K, unsigned int& X)
{
	std::cout<< "Enter row A and B "<<std::endl;
	std::cout<< "M=";
	std::cin>> M;
	std::cout<< "Enter column A and B "<<std::endl;
	std::cout<< "N=";
	std::cin>> N;
	std::cout<< "Enter column C and D "<<std::endl;
	std::cout<< "K=";
	std::cin>> K;
	std::cout<< "Enter count of matrix "<<std::endl;
	std::cout<< "X=";
	std::cin>> X;

}

struct fileWriter
{
	const char*  fname;
	std::ofstream f;
	fileWriter(const char* fn):fname(fn)
	{
		f.open(fname,std::ios::out);
		assert(f.is_open() && "File opening");

	}
	void writeint(int& i)
	{
		f<<i;
	}
	bool writechar(std::string c)
	{
		f<<c;

	}
	~fileWriter()
	{
		f.close();
	}
};

void WriteMatrix(const unsigned int M, const unsigned int N, fileWriter& fw, const unsigned int X )
{
	int m = M;
	int n = N;
	fw.writeint(m);
	fw.writechar(" x ");
	fw.writeint(n);
	fw.writechar("\n");
	for(int k = 1; k <= X; k++)
	{
		fw.writechar("<");
		fw.writeint(k);
		fw.writechar(">\n");
		for(int i=0; i < M; i++)
		{
			for(int j=0; j < N; j++)
			{      
				int x = rand() % 50 + 10;								     
				fw.writeint(x);
				fw.writechar(" ");
			}
			fw.writechar("\n");
		}
		fw.writechar("\n");
	}
}

int main()
{
	unsigned int M=0; 
	unsigned int N=0;	
	unsigned int K=0;
	unsigned int X=0;
	Input(M, N, K, X);
	fileWriter wa("./txt_files/a.txt"), wb("./txt_files/b.txt"), wc("./txt_files/c.txt"), wd("./txt_files/d.txt") ;
	WriteMatrix(M, N, wa, X);
	WriteMatrix(M, N, wb, X);
	WriteMatrix(N, K, wc, X);
	WriteMatrix(N, K, wd, X);
}
