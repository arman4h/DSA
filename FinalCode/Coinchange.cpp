#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1, 3, 4};
    int amount = 6;

    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for(int a = 1; a <= amount; a++) {
        for(int coin : coins) {
            if(a - coin >= 0 && dp[a - coin] != INT_MAX) {
                dp[a] = min(dp[a], 1 + dp[a - coin]);
            }
        }
    }

    if(dp[amount] == INT_MAX)
        cout << "Not possible\n";
    else
        cout << "Minimum coins: " << dp[amount] << endl;
}