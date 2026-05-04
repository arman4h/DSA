// Sort the whole array using the finishing time 
// 2. First Select the first sub element of the array
// 3. Compare the rest element start time with before element finish time ;
// 4. If Start Time is larger than finish time then print or else skipp the element

#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

struct Activity{
    int start, finish ; 
} ;

bool Compare(Activity a, Activity b) {
    return a.finish < b.finish ;
}

void activitySelection(vector<Activity>& arr) {
    if(arr.size() <= 0) return ; 
    sort(arr.begin(), arr.end(), Compare) ; 
    int TotalActivity = 1 ;
    int lastFinish = arr[0].finish ; 

    cout << "\nSelected Activites:" ; 
    cout << "(" << arr[0].start << "," << arr[0].finish << ")" ; 
    for(int i=1 ; i<arr.size() ; i++) {
        if (arr[i].start >= lastFinish) {
            cout << "(" << arr[i].start << "," << arr[i].finish << ")" ; 
            lastFinish = arr[i].finish ; 
            TotalActivity++ ;
        }
    }
    cout << "\nTotal Activites: " << TotalActivity ;

    
}

int main() {
    cout<< "Activity Amount: " ;
    int n ; 
    cin >> n ; 

    vector<Activity> arr(n) ; 

    for (int i=0 ; i<n ; i++) {
        cin >> arr[i].start >> arr[i].finish ;
    }

    cout << "Listed Activities: " ; 
    for (int i=0 ; i<n ; i++) {
        cout << "(" << arr[i].start << "," << arr[i].finish << ")" ; 
    }

    activitySelection(arr) ;
}