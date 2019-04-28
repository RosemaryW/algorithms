#include "MergeSort.h"
#include <iostream>

using namespace std;

int main () {
    int testArr[10] = {9, 3, 4, 2, 5, 6, 2, 4, 2, 8};
    mergeSort(testArr, 0, 9);

    for (int i = 0; i < 10; i++) {
        cout << testArr[i] << " ";
    }
    cout << endl;
    return 0;
}