#ifndef QuickSort
#define QuickSort
#endif

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// this partition method always uses a[r] as pivot
// can use a random index between l and r (inclusive) as pivot to avoid wrost case
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