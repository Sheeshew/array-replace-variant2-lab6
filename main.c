#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100

void print_array(const double a[], int n);
double mean_of_negatives(const double a[], int n);
double mean_of_positives(const double a[], int n);
void replace_elements(double a[], int n, double mean_neg, double mean_pos);

int main(void) {
    int n;
    int mode;
    double a[MAX_N];

    printf("1 - введення з клавіатури, 2 - випадкові числа: ");
    if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2)) {
        printf("Оберіть 1 або 2.\n");
        return 1;
    }

    printf("Кількість елементів (від 1 до %d): ", MAX_N);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_N) {
        printf("Некоректна кількість елементів.\n");
        return 1;
    }

    if (mode == 1) {
        for (int i = 0; i < n; i++) {
            printf("a[%d] = ", i + 1);
            if (scanf("%lf", &a[i]) != 1) {
                printf("Введіть число.\n");
                return 1;
            }
        }
    } else {
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 21 - 10;
        }
    }
    printf("Заданий масив:\n");
    print_array(a, n);

    double mean_neg = mean_of_negatives(a, n);
    double mean_pos = mean_of_positives(a, n);
    replace_elements(a, n, mean_neg, mean_pos);

    printf("Новоутворений масив:\n");
    print_array(a, n);

    return 0;
}


void print_array(const double a[], int n) {
    int i = 0;
    while (i < n) {
        printf("[%2d]=%7.2f  ", i + 1, a[i]);
        i++;
    }
    printf("\n");
}

double mean_of_negatives(const double a[], int n) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            sum += a[i];
            count++;
        }
    }

    if (count == 0) {
        return 1;
    }
    return sum / count;
}

double mean_of_positives(const double a[], int n) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            sum += a[i];
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }
    return sum / count;
}
void replace_elements(double a[], int n, double mean_neg, double mean_pos) {
    int all_positive = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) {
            all_positive = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[i] = mean_pos;
        } else if (a[i] < 0 || all_positive) {
            a[i] = mean_neg;
        }
    }
}
