#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cmath>


struct	Matrix
{
	float* m_array;
	int n_rows;
	int n_colu;
	int num_m;
	Matrix(const unsigned int M, const unsigned int K)
	{
		n_rows = M;
		n_colu = K;
		m_array = new float[M * K];
	}
	int getNumOfColumns()const
	{
		return n_colu;
	}
	int getNumOfRows()const
	{
		return n_rows;
	}
	int getNumOfMatrix()const
	{
		return num_m;
	}
	float & operator() (const unsigned int i, const unsigned int j)const
	{
		return m_array[i * getNumOfColumns() + j];
	}
	~Matrix()
	{
		delete m_array;
	}
};

struct	fileReader
{
	const char* f_name;
	std::ifstream fs;
	unsigned int row_n;
	unsigned int column_n;
	char c;
	fileReader(const char* fn):f_name(fn)
	{
		fs.open(f_name, std::ios::in);
		assert(fs.is_open() && "File opening");
		if(!(fs >> row_n && fs >> c && fs >> column_n))
		{
			std::cout<< "Cannot read matrix dimensios";
		}
	}
	bool read(float& x)
	{
		if(fs>>x)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool readint(int& x)
	{
		if(fs>>x)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool readchar(char& c)
	{
		if(fs>>c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int matrix_rows_num()
	{
		return row_n;
	}
	int matrix_column_num()
	{
		return column_n;
	}
	~fileReader()
	{
		fs.close();
	}
};

bool ReadMatrix(Matrix& a, fileReader& ra)
{
	char c;
	if(ra.readchar(c) && ra.readint(a.num_m) && ra.readchar(c))
	{
	for(int i = 0; i < a.getNumOfRows(); i++)
	{
		for(int j = 0; j < a.getNumOfColumns(); j++)
		{	
			float x = 0;		
			if(ra.read(x))
			{
				a(i,j)=x;
			}
			else
			{
				return false;
			}
		}
	}
	}
	else
	{
		return false;
	}
	return true;
}

struct fileWriter
{
	const char* f_name;
	std::ofstream fs;
	fileWriter(const char* fn):f_name(fn)
	{
		fs.open(f_name, std::ios::out);
		assert(fs.is_open() && "File opening");
	}
	void writeint(int& x)
	{
		fs<<x;
	}
	void writestring(std::string& str)
	{
		fs<<str;
	}
	~fileWriter()
	{
		fs.close();
	}
};

void Writer(int& num, fileWriter& w)
{
	std::string str = "Number of wrong matrix = ";
	std::string s = "\n";
	if(num == 0)
	{
		return;
	}
	else
	{
		w.writestring(str);
		w.writeint(num);
		w.writestring(s);
	}
}

void WriterCount(int& count, fileWriter& w, int& cou)
{
	std::string str =  "Quantity of wrong matrix = " ;
	std::string str1 = "\n";
	std::string str2 =  "Quantity of matrix = " ;
	w.writestring(str2);
	w.writeint(cou);
	w.writestring(str1);
	w.writestring(str);
	w.writeint(count);
	w.writestring(str1);
}

void Check(const Matrix& a, const Matrix& b,int& num, int& count)
{
	for(int i = 0; i < a.getNumOfRows(); i++)
	{
		for(int j = 0; j < a.getNumOfColumns(); j++)
		{
			float e = 0.001;
			float x = 0;
			x = a(i,j) - b(i,j);
			if(fabsf(x) > e)
			{
				count++;
				num = a.getNumOfMatrix();
				continue;
			}
		}
	}
}

void MatrixDimension(unsigned int& M,unsigned int& K, fileReader& ra, fileReader& rb)
{
	assert(ra.matrix_rows_num() == rb.matrix_rows_num());
	assert(ra.matrix_column_num() == rb.matrix_column_num());	
	M = ra.matrix_rows_num();
	K = rb.matrix_column_num();
}

int main()
{
	int count = 0;
	int cou=0;
	unsigned int M;
	unsigned int K;
	fileReader ra("./txt_files/y.txt"), rb("./txt_files/z.txt");
	fileWriter w("./txt_files/out_test.txt");
	MatrixDimension(M, K, ra, rb);
	Matrix a(M, K), b(M, K);
	while (ReadMatrix(a, ra) && ReadMatrix(b, rb))
	{		
		int num = 0;
		Check(a, b, num, count);
		Writer(num, w);
		cou++;
	}
	WriterCount(count, w, cou);
	return 0;
}

