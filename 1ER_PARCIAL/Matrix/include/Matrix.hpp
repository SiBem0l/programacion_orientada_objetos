#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "Vector.hpp"

#define MATRIX_ELEMENT VECTOR_ELEMENT
#define MATRIX_ELEMENT_DEFAULT VECTOR_ELEMENT_DEFAULT
#define MATRIX_ERROR Matrix(0,0)

class Matrix
{
    friend std::ostream& operator<<(std::ostream& outStream, const Matrix& m);
private:
    int rows;
    int columns;
    Vector elements;

public:
    // Constructor and destructor
    Matrix(int columns, int rows);
    Matrix(int columns, int rows, int value);
    Matrix(const Matrix& m);

    // Getters and setters
    MATRIX_ELEMENT& operator()(int row, int column);
    const MATRIX_ELEMENT& operator()(int row, int column) const;
    void setAll(int value);
    int getRows() const;
    int getColumns() const;

    // Operations MATRIX operator MATRIX
    Matrix& operator=(const Matrix& m);
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;
    Matrix operator/(const Matrix& m) const; // A * B^-1

    // Operations MATRIX operator ELEMENT
    Matrix operator*(const MATRIX_ELEMENT& num) const;
    Matrix operator/(const MATRIX_ELEMENT& num) const;

    // Functions of a matriz
    MATRIX_ELEMENT det() const;
    Matrix cofactor() const;
    Matrix transpose() const;
    Matrix adj() const;
    Matrix inv() const;

    // Flags
    static bool sameDimensions(const Matrix& a, const Matrix& b);
    bool isSquare() const;
};

#endif