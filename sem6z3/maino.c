#include <stdio.h>

void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

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

int main() {

    int n;
    printf("Enter the size of massive: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the array elements: \n");
    for (int i=0;i<n;i++){
        printf("arr[%i] = ",i+1);
        scanf("%d",arr+i);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
}

    return 0;
}




