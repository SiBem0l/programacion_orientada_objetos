#ifndef MATRIX_HPP
#define MATRIX_HPP

#define MATRIX_ELEMENT int
#define MATRIX_DEFAULT 0

class Matrix
{
private:
    MATRIX_ELEMENT** elements;
    int rows;
    int columns;

public:
    // Constructor and destructor
    Matrix(int rows, int columns);
    ~Matrix();

    // Getters and setters
    MATRIX_ELEMENT& operator()(int row, int column);
    int getRows();
    int getColumns();
};

#endif