#include <stdio.h>
#include <strlib.h>

void counting_sort(int arr[], int n) {
    int count[1000] = {0};
    int output[n];

// подсчет количества элементов каждого значения
for (int i = 0; i < n; i++) {
    count[arr[i]]++;
    }

// подсчет количества элементов меньших или равных каждому значению
for (int i = 1; i < 1000; i++) {
    count[i] += count[i-1];
    }

// заполнение результирующего массива
for (int i = n-1; i >= 0; i--) {
    output[count[arr[i]]-1] = arr[i];
    count[arr[i]]--;
    }

// копирование результирующего массива в исходный
for (int i = 0; i < n; i++) {
    arr[i] = output[i];
    }
}

int main() {
    int arr[10] = {5, 2, 8, 9, 0, 1, 6, 3, 4, 7};
    counting_sort(arr, 10);
// вывод отсортированного массива
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
