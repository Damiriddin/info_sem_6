#include "func.h"

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