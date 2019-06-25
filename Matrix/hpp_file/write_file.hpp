#ifndef WRITE_FILE_HPP
#define WRITE_FILE_HPP
#include <iostream>
#include <fstream>
#include "../hpp_file/matrix.hpp"

class FileWriter
{
private:
        const char* filename;
	int z;
        std::ofstream fs;
public:
        FileWriter(const char* );
        void write(float );
        void writechar(char );
        void WriteMatrix(const Matrix& );
	~FileWriter();
};
#endif                                         
