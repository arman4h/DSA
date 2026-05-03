// Steps to solve the merge Sorting ; 

// 1. Divide the arr untill there are one to one value ;
// 2. Compare the left and right elements ; 
// 3. Make a temp array for storing ; 
// 4. if left is low then left putted to temp or right will putted ; 
// 5. If one side all value is done then put other side data to temp ; 
// 6. Push the temp data to arr at the final .



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

void merge(int arr[], int left , int mid , int right) {
    int i = left ; 
    int j = mid+1 ; 
    int temp[100] , k= 0 ; 
    
    while( i <= mid && j <= right ){
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i] ; 
            k++ ;
            i++ ;
        }
        else {
            temp[k] = arr[j] ; 
            k++ ; 
            j++ ;
        }
    }

    while( i <= mid ) {
        temp[k] = arr[i] ;
        k++ ; 
        i++ ; 
    }

    while( j <= right) {
        temp[k] = arr[j] ; 
        k++ ; 
        j++ ; 
    }

    for ( int i =0 ; i< k ; i++) {
        arr[left+i] = temp[i] ;
    }
    
    cout << "after " << i << "st itration" << endl ;
    printArray(arr, 6) ;
}

void mergeSort(int arr[] , int left , int right) {
    if(left >= right ) return  ; 

    int mid = (left + right) / 2 ; 

    mergeSort(arr , left , mid) ; 
    mergeSort(arr, mid+1 , right) ;

    merge(arr, left , mid , right) ;
}

int main() {
    int arr[]  = {5, 3, 1,98, 24 , 17} ; 

    printArray(arr, 6) ; 

    mergeSort(arr, 0 , 5) ;

    
}