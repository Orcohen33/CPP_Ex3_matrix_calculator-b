#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>
#include "Matrix.hpp"

using namespace std;

/*
    This class represent a matrix, and it's methods are:
    - Overload operator <<
    - Overload operator >>
    - Overload operator +, -, *
    - Overload operator +=, -=, *=
    - Overload operator ==, !=
    - Overload operator <, <=, >, >=
    - Overload operator ++, --
*/
namespace zich
{

    // arithmetic operators overloading
    Matrix operator+(const Matrix &a)
    { // unary plus
        return a;
    }
    Matrix operator+(const Matrix &a, const Matrix &b)
    { // a + b
        if (a.rows != b.rows || a.cols != b.cols)
        {
            throw invalid_argument("Matrix size does not match");
        }
        Matrix c(a.rows, a.cols);
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            c.arr[i] = a.arr[i] + b.arr[i];
        }
        return c;
    }
    Matrix operator+(double a, const Matrix &b)
    { // scalar + mat
        Matrix c(b.rows, b.cols);
        for (uint i = 0; i < b.rows * b.cols; i++)
        {
            c.arr[i] = a + b.arr[i];
        }
        return c;
    }
    Matrix operator+(const Matrix &a, double b)
    { // mat + scalar
        Matrix c(a.rows, a.cols);
        c = b + a;
        return c;
    }
    Matrix operator+=(Matrix &a, const Matrix &b)
    { // a += b
        if (a.rows != b.rows || a.cols != b.cols)
        {
            throw invalid_argument("Matrix size does not match");
        }
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            a.arr[i] += b.arr[i];
        }
        return a;
    }
    Matrix operator+=(Matrix &a, double b)
    { // a += b
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            a.arr[i] += b;
        }
        return a;
    }
    Matrix operator-(const Matrix &a)
    { // unary minus
        Matrix c(a.rows, a.cols);
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            c.arr[i] = -a.arr[i];
        }
        return c;
    }
    Matrix operator-(const Matrix &a, const Matrix &b)
    { // a - b
        if (a.rows != b.rows || a.cols != b.cols)
        {
            throw invalid_argument("Matrix size does not match");
        }
        Matrix c(a.rows, a.cols);
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            c.arr[i] = a.arr[i] - b.arr[i];
        }
        return c;
    }
    Matrix operator-(double a, const Matrix &b)
    { // scalar - mat
        Matrix c(b.rows, b.cols);
        for (uint i = 0; i < b.rows * b.cols; i++)
        {
            c.arr[i] = a - b.arr[i];
        }
        return c;
    }
    Matrix operator-(const Matrix &a, double b)
    { // mat - scalar
        Matrix c(a.rows, a.cols);
        c = a + (-b);
        return c;
    }
    Matrix operator-=(Matrix &a, const Matrix &b)
    { // a -= b
        if (a.rows != b.rows || a.cols != b.cols)
        {
            throw invalid_argument("Matrix size does not match");
        }
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            a.arr[i] -= b.arr[i];
        }
        return a;
    }
    Matrix operator-=(Matrix &a, double b)
    { // a -= b
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            a.arr[i] -= b;
        }
        return a;
    }

    // Comparison operators
    bool operator==(const Matrix &a, const Matrix &b)
    {
        try
        {
            if (a.rows != b.rows || a.cols != b.cols)
            {
                throw invalid_argument("Matrix size does not match");
            }
            for (uint i = 0; i < a.rows * a.cols; i++)
            {
                if (a.arr[i] != b.arr[i])
                {
                    return false;
                }
            }
            return true;
        }
        catch (exception &e)
        {
            throw e.what();
        }
    }
    bool operator!=(const Matrix &a, const Matrix &b)
    {
        return !(a == b);
    }
    bool operator<(const Matrix &a, const Matrix &b)
    {
        try
        {
            if (a.rows != b.rows || a.cols != b.cols)
            {
                throw invalid_argument("Matrix size does not match");
            }
            int sumA = 0;
            int sumB = 0;
            for (uint i = 0; i < a.rows * a.cols; i++)
            {
                sumA += a.arr[i];
                sumB += b.arr[i];
            }
            return sumA < sumB;
        }
        catch (exception &e)
        {
            throw invalid_argument("Matrix size does not match");
        }
    }
    bool operator>(const Matrix &a, const Matrix &b)
    {
        try
        {
            if (a.rows != b.rows || a.cols != b.cols)
            {
                throw invalid_argument("Matrix size does not match");
            }
            int sumA = 0;
            int sumB = 0;
            for (uint i = 0; i < a.rows * a.cols; i++)
            {
                sumA += a.arr[i];
                sumB += b.arr[i];
            }
            return sumA > sumB;
        }
        catch (exception &e)
        {
            throw invalid_argument("Matrix size does not match");
        }
    }
    bool operator<=(const Matrix &a, const Matrix &b)
    {
        try
        {
            return !(a > b);
        }
        catch (exception &e)
        {
            throw invalid_argument("Matrix size does not match");
        }
    }
    bool operator>=(const Matrix &a, const Matrix &b)
    {
        try
        {
            return !(a < b);
        }
        catch (exception &e)
        {
            throw invalid_argument("Matrix size does not match");
        }
    }

    // increase\decrease methods
    Matrix &Matrix::operator++()
    {
        for (uint i = 0; i < this->rows * this->cols; i++)
        {
            this->arr[i] += 1;
        }
        return *this;
    }
    Matrix Matrix::operator++(int)
    {
        Matrix result(*this);
        for (uint i = 0; i < this->rows * this->cols; i++)
        {
            this->arr[i] += 1;
        }
        return result;
    }
    Matrix &Matrix::operator--()
    {
        for (uint i = 0; i < this->rows * this->cols; i++)
        {
            this->arr[i] -= 1;
        }
        return *this;
    }
    Matrix Matrix::operator--(int)
    {
        Matrix result(*this);
        for (uint i = 0; i < this->rows * this->cols; i++)
        {
            this->arr[i] -= 1;
        }
        return result;
    }

    // multiplication operators
    Matrix operator*(double scalar, const Matrix &a)
    { // scalar * a
        Matrix result(a.rows, a.cols);
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            result.arr[i] = scalar * a.arr[i];
        }
        return result;
    }
    Matrix operator*(const Matrix &a, double scalar)
    {
        return scalar * a;
    }
    Matrix Matrix::operator*(const Matrix &other)
    // override operator* with this and matrix other
    {
        if (this->cols != other.rows)
        {
            throw invalid_argument("Matrix size does not match");
        }
        Matrix result(this->rows, other.cols);
        for (uint i = 0; i < this->rows; i++)
        {
            for (uint j = 0; j < other.cols; j++)
            {
                for (uint k = 0; k < this->cols; k++)
                {
                    result.arr[i * (uint)other.cols + j] += this->arr[i * (uint)this->cols + k] * other.arr[k * (uint)other.cols + j];
                }
            }
        }
        return result;
    }
    Matrix operator*=(Matrix &a, double scalar)
    {
        for (uint i = 0; i < a.rows * a.cols; i++)
        {
            a.arr[i] *= scalar;
        }
        return a;
    }
    Matrix operator*=(double scalar, Matrix &a)
    {
        return scalar * a;
    }
    Matrix operator*=(Matrix &a, const Matrix &b)
    {
        if (a.cols != b.rows)
        {
            throw invalid_argument("Matrix size does not match");
        }
        Matrix result(a.rows, b.cols);
        for (uint i = 0; i < a.rows; i++)
        {
            for (uint j = 0; j < b.cols; j++)
            {
                for (uint k = 0; k < a.cols; k++)
                {
                    result.arr[i * (uint)b.cols + j] += a.arr[i * (uint)a.cols + k] * b.arr[k * (uint)b.cols + j];
                }
            }
        }
        a = result;
        return a;
    }

    // cin & cout override methods
    ostream &operator<<(ostream &os, const Matrix &matrix)
    {
        for (uint i = 0; i < matrix.rows; i++)
        {
            os << "[";
            for (uint j = 0; j < matrix.cols - 1; j++)
            {
                os << matrix.arr[i * (uint)matrix.cols + j] << " ";
            }
            os << matrix.arr[i * (uint)matrix.cols + (uint)matrix.cols - 1];
            os << "]";
            if (i != matrix.rows - 1)
            {
                os << "\n";
            }
        }
        return os;
    }
    /*
    input matrix, every element separated by space
    each line seperate by ", "
    Valid input: "[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"
    Invalid input: "[ 1 1 1 1 ], [ 1 1 1 1 , [ 1 1 1 1 ]]\n"
    */
    istream &operator>>(istream &is, Matrix &matrix)
    {
        string line;
        getline(is, line);
        stringstream ss(line);

        // Check the integrity of parentheses.
        int left_parentheses = 0;
        int right_parentheses = 0;
        int commas = 0;
        int spaces = 0;

        if (line[0] == '[')
        {
            left_parentheses++;
        }
        else
        {
            throw invalid_argument("Matrix input error");
        }
        for (size_t i = 1; i < line.length(); i++)
        {
            if (line[i] == '[')
            {
                left_parentheses++;
            }
            else if (line[i] == ']')
            {
                right_parentheses++;
                if (i + 1 < line.length() && line[i + 1] == ',')
                {
                    commas++;
                    if (i + 2 < line.length() && line[i + 2] == ' ')
                    {
                        spaces++;
                    }
                    else if (i + 2 < line.length() && line[i + 2] != ' ')
                    {
                        throw invalid_argument("Matrix input error");
                    }
                }
                else if (i + 1 < line.length() && line[i + 1] != ',')
                {
                    throw invalid_argument("Matrix input error");
                }
            }
            else if (line[i] == ' ')
            {
                spaces++;
            }
        }
        if (left_parentheses != right_parentheses)
        {
            throw invalid_argument("Invalid input1");
        }
        if ((commas + 1) != right_parentheses)
        {
            throw invalid_argument("Invalid input2");
        }

        int rowSum = right_parentheses;
        int colSum = (spaces + 1) / right_parentheses;

        matrix.rows = rowSum;
        matrix.cols = colSum;
        matrix.arr.resize((uint)(rowSum * colSum), 0);
        for (uint i = 0; i < matrix.rows * matrix.cols; i++)
        {
            if (isdigit(line[i]) != 0)
            {
                matrix.arr[i] = line[i] - '0';
            }
            else
            {
                continue;
            }
        }
        return is;
    }

}
