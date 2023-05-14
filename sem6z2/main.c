#include "func.h"

int main(void)
{


int n;
    printf("Enter the size of massive: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter the array elements: \n");
    for (int i=0;i<n;i++){
        printf("arr[%i] = ",i);
        scanf("%d",arr+i);
    }
    int x;
    printf("Enter the element looking for x = ");
    scanf("%d",&x);


int result = binarySearchRecursive(arr, 0, n , x);
(result == -1) ? printf("There is no such element in array!"): printf("Element's index = %d", result);
return 0;
}
