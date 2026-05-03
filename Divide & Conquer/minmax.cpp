#include<iostream> 
using namespace std ; 

pair<int, int> getMinMax(int arr[], int left , int right) {

    // Case 1: 1 Element
    if( left == right) {
        return {arr[left], arr[left]} ;
    }

    // case 2: 2 Element 
    if (right == left + 1 ) {
        return {arr[left], arr[right]} ;
    }

    // divide
    int mid = (left+right) / 2 ; 

    // conquer
    pair<int,int> small = getMinMax(arr, left, mid) ; 
    pair<int,int> big = getMinMax(arr, mid+1, right) ; 

    // combine 
    int mn = min(small.first, big.first) ; 
    int mx = max(small.second, big.second); 

    return {mn, mx} ; 

}

int main() {
    int arr[] = {12, 33, 78, 3, 34 , 45} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    pair<int, int> ans = getMinMax(arr, 0, n-1) ; 

    cout << "Min: " << ans.first << endl ;
    cout << "Max: " << ans.second << endl ;
}

