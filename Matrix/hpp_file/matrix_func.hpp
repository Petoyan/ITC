#ifndef MATRIX_FUNC_HPP
#define MATRIX_FUNC_HPP
#include <iostream>
#include "../hpp_file/matrix.hpp"
#include "../hpp_file/read_file.hpp"
#include "../hpp_file/write_file.hpp"
#include <cmath>


void Gauss_Seidel_Method(const Matrix&, const Matrix&, Matrix& , float);
void Jakob_Method(const Matrix&, const Matrix&, Matrix&, float);
void Mult_Matrix(const Matrix& , const Matrix& , Matrix& );
#endif

