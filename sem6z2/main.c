//¬озвращает позицию найденного числа (с нул€)
int binsearch (int searchInt, int *intArray, int lowIndx, int highIndx) {
    if (highIndx >= lowIndx) {
        int mid = lowIndx + (highIndx - lowIndx) / 2;

        if (intArray[mid] == searchInt)
            return mid;

        if (intArray[mid] > searchInt)
            return binsearch(searchInt, intArray, lowIndx, mid - 1);

        return binsearch(searchInt, intArray, mid + 1, highIndx);
    }

    return -1;
}




