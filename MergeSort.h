void mergeSort(int *a, int l, int r) {
    if (l < r) {
        int mid = (r + l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, r, mid);
    }
}

void merge(int *a, int l, int r, int mid) {
    int len = r - l + 1;
    int *sorted = new int[len];

    int n = l;
    int m = mid + 1;
    int i = 0;
    while (n < mid && m < r) {
        if (a[n] < a[m]) {
            sorted[i] = a[n];
            n++;
        } else {
            sorted[i] = a[m];
            m++;
        }
        i++;
    }
    
    for (; n < mid; i++, n++) {
        sorted[i] = a[n];
    }
    for (; m < r; i++, m++) {
        sorted[i] = a[m];
    }

    for (i = l; i <= r; i++) {
        a[i] = sorted[i - l];
    }
}