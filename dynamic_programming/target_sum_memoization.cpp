// Target sum - https://leetcode.com/problems/target-sum/
#include<bits/stdc++.h>
using namespace std;
/*
- state: fun(n, target) -> returns 1 if it is possible to create a subset from numbers
         1 to n and form the sum "target"

- recurrance: fun(n, target) -> fun(n-1, target + nums[n]) + 
                                fun(n-1, target - nums[n])

- base_case: fun(0, target) -> 1 if target == 0
                               else 0
*/
const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];

int target_sum(int n, int target) {
    // 1. base case
    if(n == 0) {
        if(target == 0) return 1;
        return 0;
    }

    // 2. if result is already calculated return it
    if(dp[n][target] != 0) {
        return dp[n][target];
    }

    // 3. calculate result from smaller states
    int ans1 = target_sum(n-1, target - nums[n]);
    int ans2 = target_sum(n-1, target + nums[n]);
    int ans = ans1 + ans2;

    dp[n][target] = ans;
    return ans;
}

int main() {
    int n, target;
    cin>> n >> target;

    for(int i = 1 ; i <= n ; i++) {
        cin >> nums[i];
    }

    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= target ; j++) {
            dp[i][j] = 0;
        }
    }

    cout << target_sum(n, target) << endl;
    return 0;
}
