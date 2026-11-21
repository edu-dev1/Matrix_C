#include "Matrix.h"

/* EXCEPTIONS */

MatrixSizeException::MatrixSizeException(const char* error) : std::logic_error(error){}
MatrixIndexException::MatrixIndexException(const char* error) : std::out_of_range(error){}

/* CONSTRUCTORS */

template<typename T>
Matrix<T>::Matrix(unsigned rows, unsigned columns) : __rows(rows), __columns(columns){
    if(int(rows) < 0 || int(columns) < 0){
        throw MatrixIndexException("No negative indeces.");
    }
    __matrix = new T*[__rows];
    for(unsigned r = 0; r < __rows; r++){
        __matrix[r] = new T[__columns];
    }
    
    for(unsigned r = 0; r < __rows; r++){
        for(unsigned c = 0; c < __columns; c++){
            __matrix[r][c] = false; // void matrix or zeros matrix
        }
    }
}

template<typename T>
Matrix<T>::Matrix() : Matrix<T>(2, 2){}

/* DESTRUCTOR */

template<typename T>
Matrix<T>::~Matrix(){
    for(unsigned r = 0; r < __rows; r++){
        delete[] __matrix[r];
    }
    delete[] __matrix;
}

/* Private methods */

template<typename T>
bool Matrix<T>::same_size(Matrix<T> &m1, Matrix<T> &m2){
    return (m1.__rows == m2.__rows) && (m1.__columns == m2.__columns);
}

template<typename T>
bool Matrix<T>::is_square(void){
    return __rows == __columns;
}

/* OPERATORS */

template<typename T>
T& Matrix<T>::operator()(int r, int c){
    if(r < 0 || c < 0){
        throw MatrixIndexException("No negative indeces.");
    }
    if(unsigned(r) > __rows || unsigned(c) > __columns){
        throw MatrixIndexException("Bad index.");
    }
    return __matrix[r][c];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &other)noexcept(false){
    if(! same_size(*this, other)){
        throw MatrixSizeException("Both matrices must have the same size.");
    }
    Matrix<T> matrix_result(__rows, __columns);

    for(unsigned r = 0; r < matrix_result.__rows; r++){
        for(unsigned c = 0; c < matrix_result.__columns; c++){
            matrix_result.__matrix[r][c] = __matrix[r][c] + other.__matrix[r][c];
        }
    }

    return matrix_result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T &scalar){
    
    Matrix<T> matrix_result(__rows, __columns);

    for(unsigned r = 0; r < matrix_result.__rows; r++){
        for(unsigned c = 0; c < matrix_result.__columns; c++){
            matrix_result.__matrix[r][c] = __matrix[r][c] + scalar;
        }
    }

    return matrix_result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &other)noexcept(false){
    if(! same_size(*this, other)){
        throw MatrixSizeException("Both matrices must have the same size.");
    }
    Matrix<T> matrix_result(__rows, __columns);

    for(unsigned r = 0; r < matrix_result.__rows; r++){
        for(unsigned c = 0; c < matrix_result.__columns; c++){
            matrix_result.__matrix[r][c] = __matrix[r][c] - other.__matrix[r][c];
        }
    }

    return matrix_result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T &scalar){
    
    Matrix<T> matrix_result(__rows, __columns);

    for(unsigned r = 0; r < matrix_result.__rows; r++){
        for(unsigned c = 0; c < matrix_result.__columns; c++){
            matrix_result.__matrix[r][c] = __matrix[r][c] - scalar;
        }
    }

    return matrix_result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &other)noexcept(false){
    if(__columns != other.__rows){
        throw MatrixSizeException("Invalid Matrix Size.\
            \nThe columns of the first matrix must be equal of the rows of the second matrix.");
    }
    Matrix<T> matrix_result(__rows, __columns);

    for(unsigned r = 0; r < __rows; r++){
        for(unsigned c = 0; c < other.__columns; c++){
            matrix_result.__matrix[r][c] = 0;
            for(unsigned k = 0 ; k < __columns; k++){
                matrix_result.__matrix[r][c] += __matrix[r][k] * other.__matrix[k][c];
            }
            
        }
    }

    return matrix_result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar){
    
    Matrix<T> matrix_result(__rows, __columns);

    for(unsigned r = 0; r < matrix_result.__rows; r++){
        for(unsigned c = 0; c < matrix_result.__columns; c++){
            matrix_result.__matrix[r][c] = __matrix[r][c] * scalar;
        }
    }

    return matrix_result;
}

template<typename T>
Matrix<T> Matrix<T>::transpose(void) noexcept(false){
    if(! is_square()){
        throw MatrixSizeException("Invalid Matrix Size.\
            \nThe matrix must be a square matrix.");
    }
    Matrix<T> matrix_result(__rows, __columns);

    for(unsigned r = 0; r < matrix_result.__rows; r++){
        for(unsigned c = 0; c < matrix_result.__columns; c++){
            matrix_result.__matrix[r][c] = __matrix[c][r];
        }
    }

    return matrix_result;
}

template <typename T>
float Matrix<T>::determinant(void) noexcept(false){
    if(! is_square()){
        throw MatrixSizeException("Invalid Matrix Size.\
            \nThe matrix must be a square matrix.");
    }
    int determinant = 0;
    unsigned size = __rows * __columns;
    if(size == 1){ // 1×1
        determinant = __matrix[0][0];
    }else if(size == 4){ // 2×2
        determinant = (__matrix[0][0] * __matrix[1][1]) - (__matrix[1][0] * __matrix[0][1]);
    }else if(size == 9){
        int f1, f2, f3, f4, f5, f6;
        f1 = __matrix[0][0] * __matrix[1][1] * __matrix[2][2];
        f2 = __matrix[0][1] * __matrix[1][2] * __matrix[2][0];
        f3 = __matrix[0][2] * __matrix[1][0] * __matrix[2][1];
        f4 = __matrix[0][2] * __matrix[1][1] * __matrix[2][0];
        f5 = __matrix[0][1] * __matrix[1][0] * __matrix[2][2];
        f6 = __matrix[0][0] * __matrix[1][2] * __matrix[2][1];

        determinant = f1 + f2 + f3 - f4 - f5 - f6;
    }else{
        
    }
    return determinant;
}

/* PRINT */

template<typename TT>
std::ostream &operator<<(std::ostream &out, const Matrix<TT> &matrix){
    out << '{' << std::endl;
    for (unsigned r = 0; r < matrix.__rows; r++){
        for (unsigned c = 0; c < matrix.__columns; c++){
            out << "\t" << matrix.__matrix[r][c] << " ";
        }
        out << std::endl;
    }
    out << '}';
    return out;
}
