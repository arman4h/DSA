#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArrayDC(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    return max({
        maxSubArrayDC(arr, low, mid),        // left
        maxSubArrayDC(arr, mid + 1, high),  // right
        maxCrossingSum(arr, low, mid, high) // crossing
    });
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray Sum (D&C): "
         << maxSubArrayDC(arr, 0, n - 1);
}