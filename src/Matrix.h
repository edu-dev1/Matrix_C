#ifndef Matrix_h
#define Matrix_h

#include <stdexcept>
#include <iostream>

class MatrixSizeException : public std::logic_error{
    public:
        MatrixSizeException(const char* error);
};

class MatrixIndexException : public std::out_of_range{
    public:
        MatrixIndexException(const char* error);
};

template <typename T>
class Matrix{
    private:
        unsigned __rows, __columns; 
        T **__matrix;
        inline bool same_size(Matrix<T> &m1, Matrix<T> &m2);//Returns true if `m1` has the same size that `m2`, false otherwise.
        inline bool is_square(void);
    public:
        Matrix(unsigned rows, unsigned columns); // Creates a zeros (or void) (rows × columns) matrix
        Matrix();// Creates a zeros (or void) square (2×2) matrix 
        ~Matrix();

        T& operator()(int r, int c);//Indexing for reading and writing.
        Matrix<T> operator+(Matrix<T> &other)noexcept(false);
        Matrix<T> operator+(const T &scalar);
        Matrix<T> operator-(Matrix<T> &other)noexcept(false);
        Matrix<T> operator-(const T &scalar);
        Matrix<T> operator*(Matrix<T> &other)noexcept(false);
        Matrix<T> operator*(const T &scalar);
        Matrix<T> transpose(void);//Returns the transpose of the matrix
        float determinant(void) noexcept(false);// Returns the determinant of the matrix.

        template<typename TT>
        friend std::ostream &operator<<(std::ostream &out, const Matrix<TT> &matrix);
};

#include "Matrix.tpp"

#endif
