//
// Created by blackgeorge on 6/10/19.
//

#include <iostream>

int euclid(int a, int b)
{
    if (a <= 0 || b < 0) {
        std::cout << "Incorrect arguments" << std::endl;
    }

    int temp;

    while (b > 0) {
        temp = a;
        a = b;
        b = temp % b;
    }

    return a;
}

int main()
{
    int a;
    int b;

    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;

    std::cout << "gcd(" << a << ", " << b << ") = " << euclid(a, b);
}

