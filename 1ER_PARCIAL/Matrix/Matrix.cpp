#include "Matrix.hpp"

// Constructor and destructor
Matrix::Matrix(int rows, int columns)
{
    elements = new MATRIX_ELEMENT*[rows];
    for(int row = 0; row < rows; row++)
    {
        elements[row] = new MATRIX_ELEMENT[columns];
    }
}

Matrix::~Matrix()
{
    for(int row = 0; row < rows; row++)
    {
        delete[] elements[row];
    }
}

// Getters and setters
MATRIX_ELEMENT& Matrix::operator()(int row, int column)
{
    return elements[row][column];
}

int Matrix::getRows()
{
    return rows
}