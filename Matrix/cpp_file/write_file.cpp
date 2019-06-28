#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "write_file.hpp"

FileWriter::FileWriter(const char* filen):filename(filen)
	{
		fs.open(filename, std::ios::out);
		z=1;
	}
FileWriter::~FileWriter()
	{
		fs.close();
	}
	void FileWriter::write(float x)
	{
		fs<<x;
	}
	void FileWriter::writechar(char c)
	{
		fs<<c;
	}
	void FileWriter::WriteMatrix(const Matrix& c)
	{
		if(z == 1)
		{
			write(c.getnumofRows());
			writechar('x');
			write(c.getnumofColumns());
			writechar('\n');
		}
		writechar('<');
		write(z);
		writechar('>');
		writechar('\n');
		for(int i=0; i < c.getnumofRows(); i++)
		{
			int j=0;
			float x = c(i,j);
			write(x);
			writechar(' ');
			writechar('\n');
		}
		writechar('\n');
		z++;
	}
	
