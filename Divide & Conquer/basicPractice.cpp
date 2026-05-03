// Writting a merge sorting algorithm

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

void merge(int arr[], int mid, int left , int right) {
    int i = left ; int j = mid +1 ; 
    int temp[100] ; 
    int k = 0 ; 
    
    while(i <= mid && j <= right) {
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++] ; 
        } else temp[k++] = arr[j++] ;
    } 

    while (i <= mid) temp[k++] = arr[i++] ;
    while (j <= right) temp[k++] = arr[j++] ; 

    for (int i = 0 ; i < k ; i++) {
        arr[left + i] = temp[i] ;
    }
}

void mergeSorting(int arr[], int left  , int right) {
    if (left >= right) return ; 

    int mid = (left+right) /2 ; 

    mergeSorting(arr, left, mid) ; 
    mergeSorting(arr, mid+1, right) ; 

    merge(arr, mid , left , right) ; 
}

int main() {
    int arr[] = { 8, 4, 1, 6, 10 , 8} ; 

    printArray(arr, 5) ; 
    mergeSorting(arr, 0 , 5) ; 

    printArray(arr, 5) ; 
}