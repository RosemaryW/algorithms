/*
Given two integers N and K, generate all positive integers with length N 
having an absolute difference of adjacent digits equal to K.

Examples:

Input: N = 4, K = 8
Output: 1919, 8080, 9191
Explanation:
The absolute difference between every consecutive digit of each number is 8.
For Example: 8080 (abs(8-0) = 8, abs(0-8) = 8)

Input: N = 2, K = 2
Output: 13, 24, 20, 35, 31, 46, 42, 57, 53, 68, 64, 79, 75, 86, 97
*/

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> &res, int curr_num, int len, const int &n, const int &k) {
    if (n == 0) {
        res.push_back(0);
        return;
    }
    if (len == n) {
        res.push_back(curr_num);
        return;
    }
    int last_digit = curr_num % 10;

    if (last_digit + k < 10){
        helper(res, curr_num * 10 + last_digit + k, len + 1, n, k);
    }
    if (last_digit - k >= 0){
        helper(res, curr_num * 10 + last_digit - k, len + 1, n, k);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return -1;
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]); 
    if (k < 0 || k > 9){
        return -1;
    }

    vector<int> res;
    for (int i = 1; i < 10; i++) {
        helper(res, i, 1, n, k);
    }

    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}