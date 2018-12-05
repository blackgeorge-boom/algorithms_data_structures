//
// Created by blackgeorge on 12/6/18.
//

#include <algorithm>
#include "my_functions.h"

/// Checks if there exist to numbers in the given array
/// that have sum of a given number.
int find_two_numbers(int* A, int len, int x) {

    std::sort(A, A + len);

    auto i = 0;
    auto j = len - 1;
    auto sum = 0;

    while (i < j) {
        sum = A[i] + A[j];
        if (sum == x)
            return 1;
        else if (sum < x)
            i++;
        else
            j--;
    }

    return 0;
}

int main() {

    int A[10] = {8, 9, 0, 0, 4, 5, 3, 2, 1, 6} ;

    auto result = find_two_numbers(A, 10, 16);

    std::cout << result;

}

