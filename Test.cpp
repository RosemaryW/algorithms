#include "OrderStatistics.h"
#include <iostream>

using namespace std;

int main () {
    int testArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << orderStat(testArr, 4, 0, 9) << endl;

    // for (int i = 0; i < 10; i++) {
    //     cout << testArr[i] << " ";
    // }
    // cout << endl;
    return 0;
}