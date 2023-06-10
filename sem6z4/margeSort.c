#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iso646.h>

void marge(int arr[],int leftarr[],int rightarr[],int leftsize,int rightsize);
void margeSort(int arr[],int sizearr)
{
    // массив с одним элементом уже отсортирован
    if (sizearr<2){
        return;
    }
    
    // находим средний индек и разбиваем массив на два подмассива
    int mid = sizearr/2; // неявное приведение типов

    // создаем два подмассива определённого размера
    int* leftarr = (int*)malloc(mid*sizeof(int));
    int* rightarr = (int*)malloc((sizearr - mid)*sizeof(int));

    // заполняем подмассивы соответствуюшими элементами
    for (int i = 0;i<mid; i++)
    {
        leftarr[i] = arr[i];
    }
    for(int i = mid; i<sizearr;i++){
        rightarr[i-mid] = arr[i];
    }
    // вызиваем margeSort рекурсивно для двух подмассивов
    margeSort(leftarr,mid);
    margeSort(rightarr,sizearr - mid);
    
    marge (arr,leftarr,rightarr,mid,sizearr - mid); //сливаем подмассивы
}

void marge(int arr[],int leftarr[],int rightarr[],int leftsize,int rightsize)
{
    int i=0,j=0,k = 0;
    // объеденяем подмассивы
    while (i< leftsize and j < rightsize)
    {
        if (leftarr[i] <= rightarr[j]) { 
            // сравниваем элементы подмассивов и соответственно их значению упаковываем в исходный массив
            arr[k++] = leftarr [i++];
        }
        else{
            arr[k++] = rightarr[j++];
        }
    }

    // в этих двух блоках учитывается не равность размеров подмассивов т.е
    // один массив может быть полностью записан в этом случае сравнение не нужно и оставшиеся элементы другого подмассива автоматически записываются в исходный массив
    while(i < leftsize){
        arr[k++] = leftarr[i++];
    }
    while(j<rightsize){
        arr[k++] = rightarr[j++];
    }
}

//  функция вывода 
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    int arr[] = { -5,12, 11, -110, 13, 5, 6, 7 };
    int sizearr = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    displayArray(arr, sizearr);

    margeSort(arr, sizearr);

    printf("Sorted array: ");
    displayArray(arr, sizearr);

    return 0;
      
    

}
