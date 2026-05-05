#include <iostream>
using namespace std;

int divide(int arr[], int low, int high) {
    int pivot = arr[high];   
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;            
}


void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int pivotIndex = divide(arr, low, high);  // DIVIDE

    quickSort(arr, low, pivotIndex - 1);     // CONQUER left
    quickSort(arr, pivotIndex + 1, high);    // CONQUER right
    // COMBINE → nothing required
}

int main() {
    int arr[] = {12, 4, 7, 3, 15, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
}