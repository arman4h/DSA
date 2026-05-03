#include <iostream>
using namespace std ; 

void printArray( int arr[] , int n) {
    for (int i =0 ; i<n ; i++) {
        cout << arr[i] ;
        if (i < n-1) {
            cout << ", " ;
        }
        
    }
    cout << endl ;
}

void merge(int arr[] , int left , int mid , int right) {
    int i = left ; int j = mid+1 ;
    int temp[100] ; int k = 0 ; 

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++] ; 
        } else {
            temp[k++] = arr[j++] ; 
        }
    }

    while (i <= mid) temp[k++] = arr[i++] ; 
    while (j <= right) temp[k++] = arr[j++] ; 

    for (int i= 0 ; i < k ; i++){
        arr[left + i] = temp[i] ; 
    }

}

void mergeSort(int arr[] , int left , int right) {
    if (left >= right) return ; 

    int mid = (left+right ) / 2 ; 
    mergeSort(arr, left, mid) ; 
    mergeSort(arr, mid+1 , right) ; 

    merge(arr, left , mid, right) ; 
}

int main() {
    int arr[] = {34, 34, 23, 54, 2, 56} ; 
    cout << "Before Sorting: " ;

    printArray(arr, 6) ; 

    mergeSort(arr, 0 , 5) ; 

    cout << "After Sorting: " ;

    printArray(arr, 6) ; 
}