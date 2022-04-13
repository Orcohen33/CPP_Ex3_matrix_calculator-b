#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        vector<double> arr;
        int rows;
        int cols;

    public:
        /**
         * @brief Construct a new Matrix object
         *
         * @param arr
         * @param rows
         * @param cols
         */
        // constructors
        Matrix(const vector<double> arr, int rows, int cols)
        {
            if (rows * cols != arr.size() || rows <= 0 || cols <= 0)
            {
                cout << "Error: invalid matrix dimensions" << endl;
                throw invalid_argument("Matrix size does not match the vector size");
                exit(1);
            }
            (*this).rows = rows;
            (*this).cols = cols;
            (*this).arr = arr;
        }
        Matrix(int rows, int cols)
        {
            this->rows = rows;
            this->cols = cols;
            this->arr = vector<double>((uint)(rows * cols), 0);
        }
        Matrix(const Matrix &other)
        {
            this->rows = other.rows;
            this->cols = other.cols;
            this->arr = other.arr;
        } // copy constructor

        // Overriding arithmetic operators
        friend Matrix operator+(const Matrix &a);                  // unary plus
        friend Matrix operator+(const Matrix &a, double b);        // plus scalar
        friend Matrix operator+(double a, const Matrix &b);        // plus scalar
        friend Matrix operator+(const Matrix &a, const Matrix &b); // plus
        friend Matrix operator+=(Matrix &a, const Matrix &b);      // plus equals
        friend Matrix operator+=(Matrix &a, double b);             // plus equals scalar
        friend Matrix operator-(const Matrix &a);                  // unary minus
        friend Matrix operator-(const Matrix &a, double b);        // minus scalar
        friend Matrix operator-(double a, const Matrix &b);        // minus scalar
        friend Matrix operator-(const Matrix &a, const Matrix &b); // minus
        friend Matrix operator-=(Matrix &a, const Matrix &b);      // minus equals
        friend Matrix operator-=(Matrix &a, double b);             // minus equals scalar

        // Comparison operators
        friend bool operator==(const Matrix &a, const Matrix &b); // equality
        friend bool operator!=(const Matrix &a, const Matrix &b); // inequality
        friend bool operator>(const Matrix &a, const Matrix &b);  // greater than
        friend bool operator<(const Matrix &a, const Matrix &b);  // less than
        friend bool operator>=(const Matrix &a, const Matrix &b); // greater than or equal to
        friend bool operator<=(const Matrix &a, const Matrix &b); // less than or equal to

        // Overriding increase/decrease methods
        Matrix &operator++();   // prefix
        Matrix operator++(int); // postfix
        Matrix &operator--();   // prefix
        Matrix operator--(int); // postfix

        // Overriding multiplication operators
        friend Matrix operator*(double scalar, const Matrix &a); // scalar multiplication
        friend Matrix operator*(const Matrix &a, double scalar); // scalar multiplication
        // friend Matrix operator*(const Matrix &a, const Matrix &b); // matrix multiplication
        Matrix operator*(const Matrix &other);                // matrix multiplication
        friend Matrix operator*=(Matrix &a, const Matrix &b); // matrix multiplication equals
        friend Matrix operator*=(Matrix &a, double scalar);   // scalar multiplication equals
        friend Matrix operator*=(double scalar, Matrix &a);   // scalar multiplication equals

        // cin & cout override methods

        friend ostream &operator<<(ostream &os, const Matrix &matrix); // print
        friend istream &operator>>(istream &is, Matrix &matrix);       // read

        // Matrix::~Matrix();
    };
}
