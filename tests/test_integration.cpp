#include "arraylib.h"
#include <cassert>
#include <iostream>

int main() {
    int data[] = {10, 20, 30, 40, 50};
    std::size_t n = sizeof(data) / sizeof(data[0]);

    // Проверяем, что среднее находится между мин и макс
    double avg = arr_average(data, n);
    assert(avg >= arr_min(data, n));
    assert(avg <= arr_max(data, n));

    std::cout << "[integration] All tests passed\n";
    return 0;
}