//
// Created by blackgeorge on 6/10/19.
//

#include <iostream>
#include <vector>
#include "euclid.h"

int lcm(int a, int b)
{
    return a * b / euclid(a, b);
}

int main()
{
    int a;
    int b;

    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;

    if (a <= 0 || b < 0) {
        std::cout << "Incorrect arguments" << std::endl;
    }

    std::cout << "lcm(" << a << ", " << b << ") = " << lcm(a, b) << std::endl;

    std::vector<int> v {15, 9};

    int l = 1;
    for (auto x : v)
        l = lcm(l, x);

    std::cout << "Result: " << l << std::endl;
}
