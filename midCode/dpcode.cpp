#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelectionDP(vector<Activity>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), compare);

    vector<int> dp(n, 1);     // each activity alone = 1
    vector<int> parent(n, -1); // to track solution

    // Build DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j].finish <= arr[i].start && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
    }

    // Find max value index
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    // Reconstruct selected activities
    vector<Activity> result;
    while (maxIndex != -1) {
        result.push_back(arr[maxIndex]);
        maxIndex = parent[maxIndex];
    }

    reverse(result.begin(), result.end());

    cout << "Selected activities (DP):\n";
    for (auto act : result) {
        cout << "(" << act.start << ", " << act.finish << ")\n";
    }
}

int main() {
    vector<Activity> arr = {{1,4},{3,5},{0,6},{5,7},{8,9},{5,9}};
    activitySelectionDP(arr);
}