#include "func.h"


// Функция SWAP();
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

// Фуекция быстрой сортировки quicksort();
void quicksort(int arr[], int low, int high) {
int stack[high - low + 1];


int top = -1;

stack[++top] = low;
stack[++top] = high;

while (top >= 0) {
    high = stack[top--];
    low = stack[top--];

    int pivot_index = low;
    int pivot_value = arr[high];

    for (int i = low; i < high; i++) {
        if (arr[i] < pivot_value) {
            swap(&arr[i], &arr[pivot_index]);
            pivot_index++;
        }
    }

    swap(&arr[pivot_index], &arr[high]);

    if (pivot_index - 1 > low) {
        stack[++top] = low;
        stack[++top] = pivot_index - 1;
    }

    if (pivot_index + 1 < high) {
        stack[++top] = pivot_index + 1;
        stack[++top] = high;
    }
}
}