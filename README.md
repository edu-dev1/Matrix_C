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
    cout << A.transpose() << endl;
    

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
{
        1       3 
        2       4 
}
```
