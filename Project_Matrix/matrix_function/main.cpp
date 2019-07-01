#include <iostream>
#include <cassert>       
#include <fstream>
#include <string>

int z=1;
struct Matrix
{
	int* m_array;
	int m_row;
	int m_col;
	Matrix(const unsigned int M, const unsigned int N )
	{
		m_row = M;
		m_col = N;
		m_array = new int [M*N];
	}
	int getNumberofRows()const
	{
		return m_row;
	}
	int getNumberofColumns()const
	{
		return m_col;
	}
	int & operator()(const unsigned int i, const unsigned int j) const
	{
		return m_array[i * getNumberofColumns() + j];
	}
	~Matrix()
	{
		delete m_array;
	}
};

struct FileReader
{
	std::string str;
	const char* filename;
	std::ifstream f;
	unsigned int row_n;
	unsigned int column_n;
	char c;
	FileReader(const char* fn):filename(fn)
	{
		f.open(filename,std::ios::in);
		assert(f.is_open() && "File opening");
		if(!(f >> row_n && f >> c && f >> column_n))
		{
			std::cout<<"Cannot read matrix dimensions"<<std::endl;
		}
	}
	bool read(int& i)
	{
		if(f>>i)
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
		if(f>>c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	unsigned int matrix_rows_num()
	{
		return row_n;
	}
	unsigned int matrix_columns_num()
	{
		return column_n;
	}
	~FileReader()
	{
		f.close();	
	}
};

struct FileWriter
{
	const char* fname;
	std::ofstream f;
	FileWriter(const char* fn):fname(fn)
	{
		f.open(fname,std::ios::out);
                assert(f.is_open() && "File opening");

	}
	void write(int& i)
	{
		f<<i;
	}
	bool writechar(std::string c)
	{
		f<<c;

	}
	~FileWriter()
	{
		f.close();
	}
};

bool ReadMatrix(const Matrix& m,FileReader& r)
{
	char c;
	int y=0;
	if(r.readchar(c) && r.read(y) && r.readchar(c))
	{
	for(int i=0; i< m.getNumberofRows(); i++)
	{
		for(int j=0; j<m.getNumberofColumns(); j++)
		{
			int x=0;
			if(r.read(x))
			{
				m(i,j)=x;
			
			} 
			else
		       	{
				std::cout << "Can not read" << std::endl;
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

void  AddMtrix(const Matrix& a,const Matrix& b, Matrix& c)
{
	
	assert(a.getNumberofRows() == b.getNumberofRows());
	assert(a.getNumberofColumns() == b.getNumberofColumns());	
	assert(a.getNumberofRows() == c.getNumberofRows());
	assert(a.getNumberofColumns() == c.getNumberofColumns());
	for(int i = 0; i < a.getNumberofRows(); i++){
		for(int j = 0; j < a.getNumberofColumns(); j++){
			c(i, j) = a(i, j) + b(i, j);
		}
	}
}

void MultMatrix(const Matrix& t1,const Matrix& t2, Matrix& y)
{
	assert(t1.getNumberofColumns() == t2.getNumberofRows());
	assert(t1.getNumberofRows() == y.getNumberofRows());
	assert(t2.getNumberofColumns() == y.getNumberofColumns());
	for(int i = 0; i < t1.getNumberofRows(); i++){
		for(int j = 0; j < t2.getNumberofColumns(); j++){
			int s = 0;
			for(int k = 0; k < t1.getNumberofColumns(); k++){
				s += t1(i,k) * t2(k,j);
			}
			y(i,j)=s;
		}
	}
}
	
void  WriteMatrix(const Matrix& y,FileWriter& fw)
{
	if(z==1)
	{
		int m = y.getNumberofRows();
		int n = y.getNumberofColumns();
		fw.write(m);
		fw.writechar(" x ");
		fw.write(n);
		fw.writechar("\n");
		fw.writechar("<");
		fw.write(z);
		fw.writechar(">\n");
	        for(int i=0; i < y.getNumberofRows(); i++)
        	{
               		 for(int j=0; j < y.getNumberofColumns(); j++)
               	 	{
                	     	fw.write(y(i,j));
				fw.writechar(" " );
                	}
			fw.writechar("\n");
		 }
		 fw.writechar("\n");
		 z++;
	}
	else
	{
	fw.writechar("<");
	fw.write(z);
	fw.writechar(">\n");
        for(int i=0; i < y.getNumberofRows(); i++)
        {
                for(int j=0; j < y.getNumberofColumns(); j++)
                {
                     	fw.write(y(i,j));
			fw.writechar(" " );
                }
		fw.writechar("\n");
	 }
	 fw.writechar("\n");
	 z++;
	}
}

void MatrixDimensions(unsigned int& M,unsigned int& N, unsigned int& K, FileReader& ra, FileReader& rc)
{
	M = ra.matrix_rows_num();
	N = ra.matrix_columns_num();
        K = rc.matrix_columns_num();	
}

int main()
{
	unsigned int N = 0;
	unsigned int M = 0;
	unsigned int K = 0;
	FileReader ra("./txt_files/a.txt"), rb("./txt_files/b.txt"), rc("./txt_files/c.txt"), rd("./txt_files/d.txt");
	FileWriter wy("./txt_files/y.txt");
	MatrixDimensions(M, N, K, ra, rc);
	Matrix a(M,N), b(M,N), c(N,K), d(N,K), t1(M,N), t2(N,K), y(M,K);
	while(ReadMatrix(a, ra) && ReadMatrix(b, rb) && ReadMatrix(c, rc) && ReadMatrix(d, rd))
	{
	AddMtrix(a, b, t1);
	AddMtrix(c, d, t2);
	MultMatrix(t1, t2, y);
	WriteMatrix(y, wy);
	}
	return 0;
}
