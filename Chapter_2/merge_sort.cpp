//
// Created by blackgeorge on 11/19/18.
//

#include <iostream>
#include <climits>
#include <cmath>
#include <ctime>
#include "my_functions.h"

using namespace std;

void merge(int A[], int p, int q, int r) {

    // Define limits for auxiliary arrays
    auto n1 = q - p + 1;
    auto n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (auto i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (auto j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    auto i = 0;
    auto j = 0;

    for (auto k = p; k <= r; k++)
        if (L[i] <= R[j]) A[k] = L[i++];
        else A[k] = R[j++];
}

void mergesort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main () {

    int A[10] = {8, 9, 0, 0, 4, 5, 3, 2, 1, 6} ;

    cout << "Original array\n";
    print_array(A, 10);

    std::clock_t start;

    start = std::clock();

    mergesort(A, 0, 9);

    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    cout << "Final array\n";
    print_array(A, 10);
}