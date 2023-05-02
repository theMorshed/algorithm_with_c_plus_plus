#include <bits/stdc++.h>
using namespace std;

const int N = 100;
// fibonacci memory for avoid recalculation
long long fib_memory[N];

// fibonacci recursive function
long long fibo(int n) {
    // base case
    if (n <= 2) return 1;
    
    // retrurn previous calculated value
    if (fib_memory[n] != 0) {
        return fib_memory[n];
    }
    
    // recursive calculation
    fib_memory[n] = fibo(n - 1) + fibo(n - 2);
    return fib_memory[n];
}

int main() {
    // you can calculate 1 - 92 
    int n;
    cin >> n;
    
    cout << fibo(n) << endl;

    return 0;
}