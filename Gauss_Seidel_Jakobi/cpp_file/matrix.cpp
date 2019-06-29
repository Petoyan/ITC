#include <iostream>
#include "matrix.hpp"
Matrix::Matrix(const unsigned int& M, const unsigned int& N)
        {
                n_row = M;
                n_column = N;
                m_array = new float [M * N];
        }
        int Matrix::getnumofRows()const
        {
                return n_row;
        }
        int Matrix::getnumofColumns()const
        {
                return n_column;
        }
        float & Matrix::operator()(const unsigned int i, const unsigned int j)const
        {
                return m_array[i * getnumofColumns() + j];
        }
        float & Matrix::operator()(const unsigned int i)const
        {
                return m_array[i];
        }
        Matrix::~Matrix()
        {
                delete [] m_array;
        }


