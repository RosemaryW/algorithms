void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int *a, int l, int r) {
    int pivot = a[r];
    int smallerIdx = l;
    for (int i = l; i < r; i++) {
        if (a[i] < pivot) {
            swap(&a[i], &a[smallerIdx]);
            smallerIdx++;
        }
    }
    swap(&a[smallerIdx], &a[r]);
    return smallerIdx;
}

void quickSort (int *a, int l, int r) {
    if (l < r) {
        int pivotIdx = partition(a, l, r);

        quickSort(a, l, pivotIdx - 1);
        quickSort(a, pivotIdx + 1, r);
    }
}