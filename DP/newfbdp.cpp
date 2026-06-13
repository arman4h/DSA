#include <bits/stdc++.h>

using namespace std ; 

int main() {
    int n ; 
    cin >> n ; 

    vector<int> dp(n+1) ; // taking size n+1 ; 

    dp[0] = 0 ; // assigning index 0 
    dp[1] = 1 ;  // assigning index 1

    for (int i=2 ; i <=n ; i++) { //starting from index 2 as 0,1 is already assigned .
        dp[i]= dp[i-1] + dp[i-2] ; 
    }

    cout << dp[n] ; 

    return 0 ;
}