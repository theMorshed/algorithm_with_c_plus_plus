#include <bits/stdc++.h>
using namespace std;

long long ara[101];

long long fibo(int n)
{
    if (n <= 2) return 1;
    if (ara[n] != 0) return ara[n];
    ara[n] = fibo(n - 1) + fibo(n - 2);
    return ara[n];
}

int main()
{
    cout << fibo(3) << endl;
    cout << fibo(30) << endl;
    cout << fibo(10) << endl;
    cout << fibo(419) << endl;

    return 0;
}