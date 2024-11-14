//14 лаба
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define CRT_NO_SECURE_DEPRECATE
#define N 100

// Функция для заполнения массива значениями по формуле
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        double x = i + 1; // значение для функции
        ptr_array[i] = pow(x, 2) - pow(cos(x + 1), 2);
    }
    return ptr_array;
}

// Функция для вывода элементов массива
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

// Функция для уменьшения каждого элемента массива в 10 раз
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] /= 10.0;
    }
    return ptr_array;
}

// Функция для вычисления суммы элементов массива от begin до end включительно
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end && i < N; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// Функция для поиска элемента, равного заданному значению
int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i; // возвращаем индекс найденного элемента
        }
    }
    return -1; // если элемент не найден
}

// Функция для поиска первого положительного, отрицательного или нулевого элемента
int find_first_type(double* ptr_array, int n, int type) {
    for (int i = 0; i < n; i++) {
        if ((type == 0 && ptr_array[i] > 0) ||   // первый положительный элемент
            (type == 1 && ptr_array[i] < 0) ||   // первый отрицательный элемент
            (type == 2 && ptr_array[i] == 0)) {  // первый нулевой элемент
            return i;
        }
    }
    return -1; // если элемент не найден
}

// Функция для вычисления среднего значения элементов между минимальным и максимальным элементом
double avg_between_min_max(double* ptr_array, int n) {
    int min_index = 0, max_index = 0;
    for (int i = 1; i < n; i++) {
        if (ptr_array[i] < ptr_array[min_index]) min_index = i;
        if (ptr_array[i] > ptr_array[max_index]) max_index = i;
    }
    int start = (min_index < max_index) ? min_index : max_index;
    int end = (min_index > max_index) ? min_index : max_index;
    double sum = 0.0;
    int count = 0;
    for (int i = start + 1; i < end; i++) {
        sum += ptr_array[i];
        count++;
    }
    return count > 0 ? sum / count : 0.0;
}

int main() {

    setlocale(LC_CTYPE,"RUS");
    double array[N];
    int size;

    printf("Введите размер массива > ");
    scanf_s("%d", &size);

    if (size > N) {
        printf("Ошибка: размер массива превышает максимум (%d).\n", N);
        return 1;
    }

    // Заполнение массива
    full_elements(array, size);

    // Печать элементов массива
    printf("Исходный массив:\n");
    put_elements(array, size);

    // Обработка элементов массива (уменьшение в 10 раз)
    calc_elements(array, size);
    printf("Массив после обработки (уменьшен в 10 раз):\n");
    put_elements(array, size);

    // Вычисление суммы элементов между заданными индексами
    int begin = 1, end = 3; // пример значений
    printf("Сумма элементов от %d до %d: %.2f\n", begin, end, sum_elements(array, begin, end));

    // Поиск элемента, равного заданному значению
    double element = 5.0; // пример значения для поиска
    int index = find_element(array, size, element);
    if (index != -1) {
        printf("Элемент %.2f найден на индексе %d\n", element, index);
    }
    else {
        printf("Элемент %.2f не найден\n", element);
    }

    // Поиск первого положительного элемента
    int type = 0; // 0 для положительного, 1 для отрицательного, 2 для нулевого
    int pos_index = find_first_type(array, size, type);
    if (pos_index != -1) {
        printf("Первый положительный элемент на индексе %d\n", pos_index);
    }
    else {
        printf("Положительный элемент не найден\n");
    }


    // Вычисление среднего значения элементов между минимальным и максимальным элементом
    double avg = avg_between_min_max(array, size);
    printf("Среднее значение элементов между минимальным и максимальным: %.2f\n", avg);

    return 0;
}
