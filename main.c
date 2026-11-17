#include <stdio.h>

#define MAX_N 100

void print_array(const double a[], int n);
double mean_of_negatives(const double a[], int n);
double mean_of_positives(const double a[], int n);
void replace_elements(double a[], int n, double mean_neg, double mean_pos);

int main(void) {
    int n = 14;
    double a[MAX_N] = {5, -2, 3, -4, 7, -6, 8, 1, -9, 4, -3, 6, -1, 2};

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
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

double mean_of_negatives(const double a[], int n) {
    return 0;
}

double mean_of_positives(const double a[], int n) {
    return 0;
}

void replace_elements(double a[], int n, double mean_neg, double mean_pos) {
}