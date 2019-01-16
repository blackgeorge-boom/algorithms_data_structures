//
// Created by blackgeorge on 1/9/19.
//

#include <climits>
#include <algorithm>
#include <iostream>
#include <ctime>

int cut_stick_naive(int p[], int n) {

    if (n == 0) return 0;

    auto q = INT_MIN;
    for (auto i = 1; i <= n; ++i)
        q = std::max(q, p[i] + cut_stick_naive(p, n - i));

    return q;
}

int cut_stick_memo_aux(int p[], int n, int r[]) {

    if (r[n] >= 0) return r[n];

    int q;

    if (n == 0)
        q = 0;
    else {
        q = INT_MIN;
        for (auto i = 1; i <= n; ++i)
            q = std::max(q, p[i] + cut_stick_memo_aux(p, n - i, r));
    }

    r[n] = q;

    return q;
}

int cut_stick_memo(int p[], int n) {

    int r[n + 1];
    std::fill_n(r, n + 1, INT_MIN);

    return cut_stick_memo_aux(p, n, r);
}

int cut_stick_bottom_up(int p[], int n) {

    int r[n + 1];

    r[0] = 0;

    int q;

    for (auto j = 1; j <= n; ++j) {

        q = INT_MIN;

        for (auto i = 1; i <= j; ++i)
            q = std::max(q, p[i] + r[j - i]);

        r[j] = q;
    }

    return r[n];
}

int main() {

    int N;

//    N = 11;
//    int p[N] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    N = 30;
    int p[N] = {10};

    std::clock_t start;

    std::cout << "Naive approach: \n";
    start = std::clock();
    for (auto i = 1; i < N; i++) {
        std::cout << 'r' << i << " = " << cut_stick_naive(p, i) << '\n';
    }
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    std::cout << "Memoization approach: \n";
    start = std::clock();
    for (auto i = 1; i < N; i++) {
        std::cout << 'r' << i + 1 << " = " << cut_stick_memo(p, i) << '\n';
    }
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    std::cout << "Bottom-up approach: \n";
    start = std::clock();
    for (auto i = 1; i < N; i++) {
        std::cout << 'r' << i + 1 << " = " << cut_stick_bottom_up(p, i) << '\n';
    }
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
}

