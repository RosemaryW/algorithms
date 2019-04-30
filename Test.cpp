#include "HeapSort.h"
#include <iostream>

using namespace std;

int main () {
    int testArr[10] = {3, 6, 6, 2, 5, 9, 7, 10, 2, 1};
    heapSort(testArr, 10);

    for (int i = 0; i < 10; i++) {
        cout << testArr[i] << " ";
    }
    cout << endl;
    return 0;
}