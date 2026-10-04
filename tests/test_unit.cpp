#include "arraylib.h"
#include <cassert>
#include <cmath>
#include <iostream>

static bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    int a[] = {42, 38, 51, 47, 36, 55, 49, 44, 40, 53};
    std::size_t n = sizeof(a) / sizeof(a[0]);

    // Проверка суммы (42+38+51+47+36+55+49+44+40+53 = 455)
    assert(arr_sum(a, n) == 455);
    
    // Проверка мин/макс
    assert(arr_min(a, n) == 36);
    assert(arr_max(a, n) == 55);

    // Проверка среднего (455 / 10 = 45.5)
    assert(close(arr_average(a, n), 45.5));

    // Проверка медианы (сортировка: 36, 38, 40, 42, 44, 47, 49, 51, 53, 55)
    // Среднее 44 и 47 = 45.5
    assert(close(arr_median(a, n), 45.5));

    std::cout << "[unit] All tests passed\n";
    return 0;
}