//
// Created by blackgeorge on 1/16/19.
//

#include <iostream>

int** matrix_multiplication(int **A, int arow, int acol, int **B, int brow, int bcol) {

    if (acol != brow) {
        std::cout << "Wrong dimensions\n";
        return nullptr;
    }

    int C[arow][bcol] = { 0 };

    for (auto i = 0; i < arow; ++i)
        for (auto j = 0; j < bcol; ++j) {
            C[i][j] = 0;
            for (auto k = 0; k < acol; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }

    return C;
}
