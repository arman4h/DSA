#include<bits/stdc++.h>
using namespace std ; 

vector<int> parent ; 

int Find(int x) { // Recursion 
    if (parent[x] == x) return x ; 

    return parent[x] = Find(parent[x]) ; 
}

void Union(int a, int b) {
    a = Find(a) ;
    b = Find(b) ; 

    if(a!=b) {
        parent[b] = a ; 
    }
}

int main() {
    int n= 5 ; 

    parent.resize(n+1) ; 

    for(int i= 1 ; i<=n ; i++) {
        parent[i] = i ; 
    }

    Union(1,2) ; 
    Union(2,3) ; 
    cout << (Find(1) == Find (3)) ; 

    return 0 ;


}