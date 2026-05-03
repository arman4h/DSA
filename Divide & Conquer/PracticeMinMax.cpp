#include<iostream>
using namespace std ; 

pair<int, int> getMinMax(int arr[], int left, int right) {

    if (left == right) {
        return {arr[left], arr[left]} ; 
    }

    if( right == left+1) {
        return {arr[left], arr[right]} ; 
    }

    int mid = (left + right) / 2 ; 


    pair<int, int> small = getMinMax(arr, left, mid) ;
    pair<int, int> big = getMinMax(arr, mid+1, right) ;


    int low = min(small.first, big.first) ; 
    int high = max(small.second, big.second) ; 

    return {low, high} ;
}

int main() {
    int arr[] = {5, 3, 21, 5, 1, 7} ; 

    int n = sizeof(arr) / sizeof(arr[0]) ; 

    pair<int, int> result = getMinMax(arr, 0 , n-1) ; 

    int min = result.first ; 
    int max = result.second ; 

    cout << "Min: " << min << endl ; 
    cout << "Max: " << max << endl ; 

    return 0 ;
}