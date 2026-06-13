#include <bits/stdc++.h>
using namespace std; 

int main() {
    vector<int> coins = {1,3,4} ; 
    int amount = 6 ; 

    vector<int> dp(amount+1, INT_MAX) ; 

    dp[0] = 0 ; 

    for(int x=1 ; x<=amount ; x++) {
        for(int coin : coins) {
            if(x-coin >=0 && dp[x-coin] !=INT_MAX) {
                dp[x] = min(dp[x] , dp[x-coin]+1) ;
            }
        }
    }

    cout << dp[amount] ; 

    return 0 ;
}