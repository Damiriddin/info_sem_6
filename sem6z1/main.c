
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

#define SWAP(t, a, x, y) do {t u=a[x]; a[x]=a[y]; a[y]=u;} while (0)

int main(void) {
    int Array[MAX_SIZE];
    int length = 0;
    int index1, index2;
    char next = 0;

    while (scanf("%d%c", &Array[length], &next) != EOF && length < MAX_SIZE) {
        ++length;

        if (next == '\n')
            break;

        if (length >= MAX_SIZE) {
            printf("Error: the number of entered numbers is greater than the maximum allowable");
            exit(1);
        }
    }

    scanf("%d %d", &index1, &index2);

    SWAP(int, Array, index1, index2);

    // Распечатка массива
    for (int i = 0; i < length; ++i)
        printf("%d ", Array[i]);
}


