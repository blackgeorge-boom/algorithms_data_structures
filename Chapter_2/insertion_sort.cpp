//
// Created by blackgeorge on 11/19/18.
//

#include <ctime>
#include "my_functions.h"

using namespace std;

void insertion_sort(int A[], int len) {

    for (auto j = 1; j < len; j++) {

        auto key = A[j];
        auto i = j - 1;

        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = key;
    }
}

int main() {

    int A[10] = {8, 9, 0, 0, 4, 5, 3, 2, 1, 6} ;

    cout << "Original array\n";
    print_array(A, 10);

    std::clock_t start;

    start = std::clock();

    insertion_sort(A, 10);

    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    cout << "Final array\n";
    print_array(A, 10);
}
