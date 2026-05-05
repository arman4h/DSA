#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& arr) {
    sort(arr.begin(), arr.end(), compare);

    cout << "Selected activities:\n";
    int lastFinish = arr[0].finish;
    cout << "(" << arr[0].start << ", " << arr[0].finish << ")\n";

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].start >= lastFinish) {
            cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";
            lastFinish = arr[i].finish;
        }
    }
}

int main() {
    vector<Activity> arr = {{1,4},{3,5},{0,6},{5,7},{8,9},{5,9}};
    activitySelection(arr);
}