//
// Created by blackgeorge on 6/10/19.
//

#include <iostream>

int euclid(int a, int b)
{
    if (b == 0)
        return a;
    else
        return euclid(b, a % b);
}
