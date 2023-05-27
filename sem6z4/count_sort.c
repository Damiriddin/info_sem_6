#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n)
{
    int output[n];
    int i, min, max;
    min = max = arr[0];
    // max and min - find
    for (i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int countsize = max - min + 1;
    int *count = (int *)malloc(countsize * sizeof(int));
    if (count == NULL)
    {
        printf("Memory Error!");
    }

   
    // подсчитываем частоту вхождений элементов
    for (i = 0; i < n; i++)
    {
        count[arr[i] - min] = count[arr[i] - min] + 1;
    }

       int k = 0;
    for (i = 0; i < countsize; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[k++] = i + min;
        }
    }
}



int main()
{
    int size;
    int arr[] = {-99, 99, 85, 7, 4, 0, 5, 45, 75, 10};
    size = sizeof(arr) / sizeof(int);
    counting_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
