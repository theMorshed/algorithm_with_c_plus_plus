#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long dp[N];
/*
    i. state: find the nth fibonacci number
    ii. equation: fib(n) = fib(n - 1) + fib(n - 2)
    iii. base case: fib(1) = 1 and fib(2) = 1
*/

int main()
{
    int n;
    cin >> n;

    // base case
    dp[1] = 1;
    dp[2] = 1;

    // iterative equation
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;

    return 0;
}