//
// Created by blackgeorge on 1/16/19.
//

#include <iostream>

int** matrix_multiplication(int A[][3], int arow, int acol, int B[][3], int brow, int bcol)
{
    if (acol != brow) {
        std::cout << "Wrong dimensions\n";
        return nullptr;
    }

    int** C = nullptr;
    C = new int*[arow];

    for (auto i = 0; i < arow; ++i) {

        C[i] = new int[bcol];

        for (auto j = 0; j < bcol; ++j) {

            C[i][j] = 0;

            for (auto k = 0; k < acol; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main()
{
    // Simple matrices
    int a[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
    };

    int b[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
    };

    int** c = nullptr;

    c = matrix_multiplication(a, 3, 3, b, 3, 3);

    for (auto i = 0; i < 3; ++i) {
        for (auto j = 0; j < 3; ++j)
            std::cout << c[i][j] << ' ';
        std::cout << '\n';
    }
}
