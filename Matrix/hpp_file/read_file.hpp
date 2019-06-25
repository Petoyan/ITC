#ifndef READ_FILE_HPP
#define READ_FILE_HPP
#include <iostream>
#include <fstream>
#include "../hpp_file/matrix.hpp"

class FileReader
{
private:
        const char* fname;
        std::ifstream fs;
        unsigned int m_row;
        unsigned int m_column;
        char c;
public:
        FileReader(const char* );
        ~FileReader();
        bool read(float& );
	bool readchar(char& );
        int getnumrow();
        int getnumcolumn();
 	bool readmatrix(Matrix&);
 };
#endif
