#include "arraylib.h"
#include <iostream>
#include <iomanip>
#include <cstddef>

int main() {
    int harvest[] = {
        42, 38, 51, 47, 36,
        55, 49, 44, 40, 53
    };

    const std::size_t n = sizeof(harvest) / sizeof(harvest[0]);

    std::cout << "=== Урожайность полей (Вариант 20) ===\n";
    std::cout << "Количество полей: " << n << "\n\n";

    // Настройка вывода дробных чисел
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Суммарная урожайность: " << arr_sum(harvest, n) << "\n";
    std::cout << "Средняя урожайность:   " << arr_average(harvest, n) << "\n";
    std::cout << "Минимальное значение:  " << arr_min(harvest, n) << "\n";
    std::cout << "Максимальное значение: " << arr_max(harvest, n) << "\n";
    std::cout << "Медиана:               " << arr_median(harvest, n) << "\n";

    return 0;
}