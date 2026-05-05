#include <iostream>
#include <utility>   // for std::pair
using namespace std;

pair<int,int> getMinMax(int arr[], int low, int high) {

    // Base case: 1 element
    if (low == high)
        return pair<int,int>(arr[low], arr[low]);

    // Base case: 2 elements
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return pair<int,int>(arr[low], arr[high]);
        else
            return pair<int,int>(arr[high], arr[low]);
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    pair<int,int> left  = getMinMax(arr, low, mid);
    pair<int,int> right = getMinMax(arr, mid + 1, high);

    // Combine
    int mn = min(left.first, right.first);
    int mx = max(left.second, right.second);

    return pair<int,int>(mn, mx);
}

int main() {
    int arr[] = {12, 45, 7, 3, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int,int> ans = getMinMax(arr, 0, n - 1);

    cout << "Minimum: " << ans.first << endl;
    cout << "Maximum: " << ans.second << endl;
}