//
// Created by blackgeorge on 12/6/18.
//

#include <iostream>

#ifndef CLRS_MY_FUNCTIONS_H
#define CLRS_MY_FUNCTIONS_H

void print_array(int A[], int len) {
    for (auto i = 0; i < len; i++) std::cout << A[i] << ' ';
    std::cout << '\n' << '\n';
}

#endif //CLRS_MY_FUNCTIONS_H
