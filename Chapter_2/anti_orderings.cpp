//
// Created by blackgeorge on 11/19/18.
//

#include <iostream>
#include <climits>
#include <cmath>
#include <ctime>
#include "my_functions.h"

using namespace std;

int merge(int A[], int p, int q, int r) {

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
    auto count = 0;

    auto k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        }
        else {
//            cout << "Inversion: " << L[i] << ", " << R[j] << '\n';
            A[k++] = R[j++];
//            cout << "j " << j << '\n';
            count += j;
        }
    }

    if (i == n1)
        for (auto m = j; m < n2; m++)
            A[k++] = R[m];

    if (j == n2) {
        for (auto m = i; m < n1; m++) {
//            cout << "Inversion: " << L[m] << ", " << R[j] << '\n';
            A[k++] = L[m];
            count += n2;
        }
    }
    return count;
}

int mergesort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        cout << "q: " << q << '\n';
        auto left = mergesort(A, p, q);
        auto right = mergesort(A, q + 1, r);
        cout << "left: " << left << " right: " << right << '\n';
        return left + right + merge(A, p, q, r);
    }
    return 0;
}

int main () {

    int A[5] = {5, 4, 3, 2, 1} ;

    cout << "Original array\n";
    print_array(A, 5);

    std::clock_t start;

    start = std::clock();

    auto anti = mergesort(A, 0, 2);

    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    cout << "Final array\n";
    print_array(A, 5);
    cout << "Anti: " << anti;
}