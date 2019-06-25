#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>

class Matrix
{
private:
        float* m_array;
        int n_row = 0;
        int n_column = 0;
public:
        Matrix(const unsigned int& , const unsigned int& );
        int getnumofRows()const;
        int getnumofColumns()const;
        float & operator()(const unsigned int i, const unsigned int j)const;
        float & operator()(const unsigned int i)const;
	~Matrix();
};
#endif
