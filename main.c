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
