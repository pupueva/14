//14 ����
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define CRT_NO_SECURE_DEPRECATE
#define N 100

// ������� ��� ���������� ������� ���������� �� �������
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        double x = i + 1; // �������� ��� �������
        ptr_array[i] = pow(x, 2) - pow(cos(x + 1), 2);
    }
    return ptr_array;
}

// ������� ��� ������ ��������� �������
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

// ������� ��� ���������� ������� �������� ������� � 10 ���
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] /= 10.0;
    }
    return ptr_array;
}

// ������� ��� ���������� ����� ��������� ������� �� begin �� end ������������
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end && i < N; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// ������� ��� ������ ��������, ������� ��������� ��������
int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i; // ���������� ������ ���������� ��������
        }
    }
    return -1; // ���� ������� �� ������
}

// ������� ��� ������ ������� ��������������, �������������� ��� �������� ��������
int find_first_type(double* ptr_array, int n, int type) {
    for (int i = 0; i < n; i++) {
        if ((type == 0 && ptr_array[i] > 0) ||   // ������ ������������� �������
            (type == 1 && ptr_array[i] < 0) ||   // ������ ������������� �������
            (type == 2 && ptr_array[i] == 0)) {  // ������ ������� �������
            return i;
        }
    }
    return -1; // ���� ������� �� ������
}

// ������� ��� ���������� �������� �������� ��������� ����� ����������� � ������������ ���������
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

    printf("������� ������ ������� > ");
    scanf_s("%d", &size);

    if (size > N) {
        printf("������: ������ ������� ��������� �������� (%d).\n", N);
        return 1;
    }

    // ���������� �������
    full_elements(array, size);

    // ������ ��������� �������
    printf("�������� ������:\n");
    put_elements(array, size);

    // ��������� ��������� ������� (���������� � 10 ���)
    calc_elements(array, size);
    printf("������ ����� ��������� (�������� � 10 ���):\n");
    put_elements(array, size);

    // ���������� ����� ��������� ����� ��������� ���������
    int begin = 1, end = 3; // ������ ��������
    printf("����� ��������� �� %d �� %d: %.2f\n", begin, end, sum_elements(array, begin, end));

    // ����� ��������, ������� ��������� ��������
    double element = 5.0; // ������ �������� ��� ������
    int index = find_element(array, size, element);
    if (index != -1) {
        printf("������� %.2f ������ �� ������� %d\n", element, index);
    }
    else {
        printf("������� %.2f �� ������\n", element);
    }

    // ����� ������� �������������� ��������
    int type = 0; // 0 ��� ��������������, 1 ��� ��������������, 2 ��� ��������
    int pos_index = find_first_type(array, size, type);
    if (pos_index != -1) {
        printf("������ ������������� ������� �� ������� %d\n", pos_index);
    }
    else {
        printf("������������� ������� �� ������\n");
    }


    // ���������� �������� �������� ��������� ����� ����������� � ������������ ���������
    double avg = avg_between_min_max(array, size);
    printf("������� �������� ��������� ����� ����������� � ������������: %.2f\n", avg);

    return 0;
}
