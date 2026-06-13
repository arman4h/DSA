#include <iostream>
using namespace std;

void printFibonacci(int n) {
    long long first = 0, second = 1, next;

    cout << "Fibonacci Series up to " << n << " terms:" << endl;

    for (int i = 0; i < n; i++) {
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        printFibonacci(n);
    }

    return 0;
}