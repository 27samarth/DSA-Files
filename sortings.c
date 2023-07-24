#include <stdio.h>
#include <string.h>
#include <time.h>

#define size 10000

void print_array(int a[size], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void bubblesort(int a[size], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("After sorting...\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void selectionsort(int a[size], int n) {
    int indexofmin, temp, j;
    for (int i = 0; i < n - 1; i++) {
        indexofmin = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[indexofmin]) {
                indexofmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;
    }
}

void insertionsort(int a[size], int n) {
    int key, i, j;
    for (i = 1; i < n; i++) {
        j = i - 1;
        key = a[i];
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void store_array(int a[size], int n, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    int i;
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", a[i]);
    }
    fclose(fp);
}

int main() {
    int a[size], n, rnum;
    float duration;
    clock_t start, end;
    int first, last;
    char filename[50];

    printf("Enter the interval: ");
    scanf("%d %d", &first, &last);
    printf("Enter number of random numbers to be generated: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % (last + 1 - first) + first;
    }

    start = clock();
    bubblesort(a, n);
    end = clock();
    duration = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nDuration of bubble sort: %f seconds\n", duration);

    printf("Enter filename to store sorted array: ");
    scanf("%s", filename);
    store_array(a, n, filename);

    start = clock();
    selectionsort(a, n);
    end = clock();
    duration = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nDuration of selection sort: %f seconds\n", duration);
    printf("Enter filename to store sorted array\n");
