# Matrix_C
A Matrix C++ library .

# Example of use:
```c++
#include "Matrix/Matrix.h"
#include <iostream>

using namespace std;

int main(void){

    int r = 2, c = 2;
    Matrix<int> A(r, c), B(r, c);

    for(int i = 0, x = 1; i < r; i++){
        for(int j = 0; j < c; j++){
            A(i, j) = x++;
        }
    }

    for(int i = 0, x = 5; i < r; i++){
        for(int j = 0; j < c; j++){
            B(i, j) = x++;
        }
    }

    cout << "A" << endl;
    cout << A << endl;
    cout << "B" << endl;
    cout << B << endl;
    cout << "A + B" << endl;
    cout << A + B << endl;
    cout << "A + 2" << endl;
    cout << A + 2 << endl;
    cout << "A × B"<< endl;
    cout << A * B << endl;
    cout << "A · 2"<< endl;
    cout << A * 2 << endl;
    cout << "A^T" << endl;
    cout << A.transpose() << endl;

    /* Determinant */ (currently only available for 1x1, 2x2, or 3x3 matrices.)
    Matrix<int> C(3, 3);
    int array[9] = {1, 2, 0, -1, 3, 1, 2, 5, 2}, i = 0;
   
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            C(r, c) = array[i++];
        }
    }
    cout << 'C' << endl;
    cout << C << endl;
    cout << "Determinant = " << C.determinant() << endl;
    return 0;
}
```
# Output:
```consolas
A
{
        1       2 
        3       4 
}
B
{
        5       6 
        7       8 
}
A + B
{
        6       8 
        10      12 
}
A + 2
{
        3       4 
        5       6 
}
A × B
{
        19      22 
        43      50 
}
A · 2
{
        2       4 
        6       8 
}
A^T
{
        1       3 
        2       4 
}
C
{
        1       2       0 
        -1      3       1 
        2       5       2 
}
Determinant = 9
```
