//
// Created by blackgeorge on 7/7/19.
//

#include <utility>
#include <vector>
#include <climits>
#include <iostream>
#include <iomanip>

typedef std::vector<std::vector<int>> Vector2d;

void print_2d_vector (Vector2d vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << std::setw(5) << vec[i][j] << " " << std::setw(5);
        }
        std::cout << std::endl;
    }
}

std::pair<Vector2d, Vector2d> matrix_ordering(std::vector<int> p)
{
    auto n = p.size() - 1;

    Vector2d m;
    m.resize(n, std::vector<int>(n, 0));

    for (auto i = 0; i < n; ++i)
        m[i][i] = 0;

    int j;
    int q;

    Vector2d s;
    s.resize(n, std::vector<int>(n, 0));

    for (auto l = 2; l <= n; ++l)

        for (auto i = 0; i < n - l + 1; ++i) {

            j = i + l - 1;
            m[i][j] = INT_MAX;

            for (auto k = i; k < j; ++k) {

                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }

    return std::pair<Vector2d, Vector2d>{m, s};
}

void print_opt_ordering(Vector2d s, int i, int j)
{
    if (i == j) {
        std::cout << "A" << i;
        return;
    }
    else {
        std::cout << "(";
        auto k = s[i][j];
        print_opt_ordering(s, i, k);
        print_opt_ordering(s, k + 1, j);
        std::cout << ")";
    }
}

int main()
{
    std::vector<int> p = {30, 35, 15, 5, 10, 20, 25};

    auto res = matrix_ordering(p);
    auto m = res.first;
    auto s = res.second;

    print_2d_vector(m);
    std::cout << "================" << std::endl;

    print_2d_vector(s);
    std::cout << "================" << std::endl;

    print_opt_ordering(s, 0, p.size() - 2);
}

