#include <iostream>
#include "read_file.hpp"
#include <fstream>
#include <cassert>
#include "matrix.hpp"

FileReader::FileReader(const char* fn):fname(fn)
	{
		fs.open(fname,std::ios::in);
		assert(fs.is_open());
		if(!(fs >> m_row && fs >> c && fs >> m_column))
		{
			std::cout << "can not read" << "\n";
		}
	}
FileReader::~FileReader()
	{
		fs.close();
	}
	bool FileReader::read(float& x)
	{
		if(fs>>x)
		{
			return true;
		}else
		{
			return false;
		}       
	}
	bool FileReader::readchar(char& c)
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
	int FileReader::getnumrow()
	{
		return m_row;
	}
	int FileReader::getnumcolumn()
	{
		return m_column;
	}
	bool FileReader::readmatrix(Matrix& a)
	{
		float x;
		char c;
		if(readchar(c) && read(x) && readchar(c))
		{
			for(int i=0; i < m_row; i++)
			{
				for(int j=0; j < m_column; j++)
				{
					float x=0;
					if(read(x))
					{
						a(i,j) = x;
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

