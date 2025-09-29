#include "Matrix.hpp"

// Constructor and destructor
Matrix::Matrix(int newColumns, int newRows) : rows(newRows),
                                              columns(newColumns)

{
    elements = Vector(getRows()*getColumns(), MATRIX_ELEMENT_DEFAULT);
}
Matrix::Matrix(int newColumns, int newRows, int value) : rows(newRows),
                                                         columns(newColumns),
                                                         elements(newColumns*newRows, value)
{   
}
Matrix::Matrix(const Matrix& m)
{
    columns = m.getColumns();
    rows = m.getRows();
    *this = m;
}

// Getters and setters
MATRIX_ELEMENT& Matrix::operator()(int column, int row)
{
    int linearIndex = row*getColumns() + column;
    return elements[linearIndex];
}
const MATRIX_ELEMENT& Matrix::operator()(int column, int row) const
{
    int linearIndex = row*getColumns() + column;
    return elements[linearIndex];
}

void Matrix::setAll(int value)
{
    for(int column = 0; column < getColumns(); column++)
    {
        for(int row = 0; row < getRows(); row++)
        {
            (*this)(column, row) = value;
        }
    }
}

int Matrix::getRows() const 
{
    return rows;
}

int Matrix::getColumns() const
{
    return columns;
}

// Operators
Matrix& Matrix::operator=(const Matrix& m)
{
    columns = m.getColumns();
    rows = m.getRows();
    elements = m.elements;
    return *this;
}

static Matrix addSameSize(const Matrix& a, const Matrix& b)
{
    Matrix ans = Matrix(a.getColumns(), a.getRows());
    for(int row = 0; row < a.getRows(); row++)
    {
        for(int column = 0; column < a.getColumns(); column++)
        {
            ans(column, row) = a(column, row) + b(column, row);
        }
    }
    return ans;
}
Matrix Matrix::operator+(const Matrix& m) const
{
    Matrix ans(MATRIX_ERROR);
    if(Matrix::sameDimensions(*this, m))
    {
        ans = addSameSize(*this, m);
    }
    return ans;
}

static Matrix subtractSameSize(const Matrix& a, const Matrix& b)
{
    Matrix ans = Matrix(a.getColumns(), a.getRows());
    for(int row = 0; row < a.getRows(); row++)
    {
        for(int column = 0; column < a.getColumns(); column++)
        {
            ans(column, row) = a(column, row) - b(column, row);
        }
    }
    return ans;
}
Matrix Matrix::operator-(const Matrix& m) const
{
    Matrix ans(MATRIX_ERROR);
    if(Matrix::sameDimensions(*this, m))
    {
        ans = subtractSameSize(*this, m);
    }
    return ans;
}

static Matrix product(const Matrix& a, const Matrix& b)
{
    Matrix result(b.getColumns(), a.getRows());
    for (int i = 0; i < a.getRows(); ++i) {           // iterate over rows of A
        for (int j = 0; j < b.getColumns(); ++j) {    // iterate over columns of B
            MATRIX_ELEMENT sum = MATRIX_ELEMENT_DEFAULT;
            for (int k = 0; k < a.getColumns(); ++k) { // dot product
                sum += a(k, i) * b(j, k);
            }
            result(j, i) = sum;
        }
    }

    return result;
}
Matrix Matrix::operator*(const Matrix& m) const
{
    Matrix ans(MATRIX_ERROR);
    if(getColumns() == m.getRows())
    {
        ans = product(*this, m);
    }   
    return ans;
}
Matrix Matrix::operator*(const MATRIX_ELEMENT& num) const
{
    Matrix ans = *this;
    ans.elements *= num;
    return ans;
}

Matrix Matrix::operator/(const MATRIX_ELEMENT& num) const
{
    Matrix ans = *this;
    ans.elements /= num;
    return ans;
}

// Functions of a Matrix
static Matrix minorMatrix(const Matrix& m, int skipColumn, int skipRow)
{
    Matrix minor(m.getColumns() - 1, m.getRows() - 1, 0);
    for (int column = 0; column < m.getColumns(); column++)
    { 
        if(column != skipColumn)
        {
            int minorColumn = column;
            if(column > skipColumn)
            {
                minorColumn = column - 1;
            }
            for(int row = 0; row < m.getRows(); row++)
            {
                if(row != skipRow)
                {
                    int minorRow = row;
                    if(row > skipRow)
                    {
                        minorRow = row - 1;
                    }
                    minor(minorColumn, minorRow) = m(column, row);
                }    
            }

        }
    }
    return minor;
}
Matrix Matrix::cofactor() const
{
    Matrix ans(this->getColumns(), this->getRows());
    for(int row = 0; row < ans.getRows(); row++)
    {
        for(int column = 0; column < ans.getColumns(); column++)
        {
            bool indexEven = (row + column) % 2 == 0;
            if(indexEven)
            {
                ans(column, row) = minorMatrix(*this, column, row).det();
            }else
            {
                ans(column, row) = minorMatrix(*this, column, row).det()* (-1);
            }
        }
    }
    return ans;
}

MATRIX_ELEMENT Matrix::det() const
{
    const Matrix& m = (*this);
    MATRIX_ELEMENT ans = MATRIX_ELEMENT_DEFAULT;
    if(isSquare())
    {
        if(getRows() == 1)
        {
            ans = m(0,0);
        }
        else if(getRows() == 2)
        {
            ans = m(0,0)*m(1,1) - m(1,0)*m(0,1);
        }
        else
        {
            int column = 0;
            for(int row = 0; row < getRows(); row++)
            {
                bool indexEven = (row + column) % 2 == 0; // i+j is even
                if(indexEven)
                {
                    ans += minorMatrix(m, column, row).det() * m(column, row);
                }
                else
                {
                    ans -= minorMatrix(m, column, row).det() * m(column, row);
                }
            }
        }
    }
    return ans;
}

Matrix Matrix::transpose() const
{
    Matrix ans(getRows(), getColumns());
    for(int row = 0; row < ans.getRows(); row++)
    {
        for(int column = 0; column < ans.getColumns(); column++)
        {
            ans(row, column) = (*this)(column, row);
        }
    }
    return ans;
}

Matrix Matrix::adj() const
{
    Matrix ans(getColumns(), getRows());
    ans = cofactor().transpose();
    return ans;
}

Matrix Matrix::inv() const //det != 0
{
    Matrix ans(MATRIX_ERROR);
    MATRIX_ELEMENT det = (*this).det();
    if(det != MATRIX_ELEMENT_DEFAULT)
    {
        ans = adj() / det;
    }
    return ans;
}

// Flags
bool Matrix::sameDimensions(const Matrix& a, const Matrix& b)
{
    return (a.getColumns() == b.getColumns()) && (a.getRows() == b.getRows());
}

bool Matrix::isSquare() const
{
    return getColumns() == getRows();
}

// Console print
std::ostream& operator<<(std::ostream& outStream, const Matrix& m)
{
    for(int column = 0; column < m.getColumns(); column++)
    {
        for(int row = 0; row < m.getRows(); row++)
        {
            outStream << m(column, row) << " ";
        }
        outStream << std::endl;
    }
    return outStream;
}