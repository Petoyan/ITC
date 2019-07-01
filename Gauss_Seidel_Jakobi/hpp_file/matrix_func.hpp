#ifndef MATRIX_FUNC_HPP
#define MATRIX_FUNC_HPP
#include <iostream>
#include "../hpp_file/matrix.hpp"
#include "../hpp_file/read_file.hpp"
#include "../hpp_file/write_file.hpp"
#include <cmath>


bool Gauss_Seidel_Method(const Matrix&, const Matrix&, Matrix& , float);
bool Jakob_Method(const Matrix&, const Matrix&, Matrix&, float);
void Mult_Matrix(const Matrix& , const Matrix& , Matrix& );
bool Matrix_Equal(const Matrix& , const Matrix& , float );
void Gauss_Method( Matrix& , Matrix& , Matrix& );
#endif

