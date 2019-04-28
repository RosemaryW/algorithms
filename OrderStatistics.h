#include "QuickSort.h"
#include <climits>

// finding the kth smallest element in an unsorted array
// assumption is that all the elements in the given array are distinct
// note argument l and r are the first and last index of the array, respectively
// the return value is the index of the kth smallest element in the given array

int orderStat (int *a , int k, int l, int r) {
    if (k > 0 && k <= r - l + 1) {
        int pivotIdx = partition(a, l, r);
        if (k == pivotIdx - l + 1) {
            return k + l - 1;
        } else if (k < pivotIdx - l + 1) {
            return orderStat(a, k, l, pivotIdx - 1);
        } else {
            return orderStat(a, k + l - pivotIdx - 1, pivotIdx + 1, r);
        }
    }

    // or throw an error here
    return INT_MAX;
}