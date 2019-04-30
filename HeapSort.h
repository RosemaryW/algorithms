#ifndef HeapSort
#define HeapSort
#endif

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int *a, int root, int size) {
    int largest = root;
    int l = root * 2 + 1;
    int r = l + 1;

    if (l < size && a[l] > a[largest]) {
        largest = l;
    }
    if (r < size && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != root) { // either the left or the right child is larger than root
        swap(&a[largest], &a[root]);
        maxHeapify(a, largest, size);
    }
}

void buildMaxHeap(int *a, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(a, i, size);
    }
}

void heapSort(int *a, int size) {
    buildMaxHeap(a, size);
    for (int i = size - 1; i >= 0; i--) {
        swap(&a[i], &a[0]);
        maxHeapify(a, 0, i);
    }
}