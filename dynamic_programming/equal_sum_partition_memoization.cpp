// Equal sum partition - https://leetcode.com/problems/partition-equal-subset-sum/
#include<bits/stdc++.h>
using namespace std;
/*
- state: fun(n, target) -> returns 1 if it is possible to create a subset from numbers
         1 to n and form the sum "target"

- recurrance: fun(n, target) -> fun(n-1, target) OR 
                                fun(n-1, target - nums[n]) if target >= nums[n]

- base_case: fun(0, target) -> 1 if target == 0
                               else 0
*/
const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];

/*

*/

int equal_sum_partition(int n, int target) {
    // 1. base case
    if(n == 0) {
        if(target == 0) return 1;
        return 0;
    }
    // 2. if result is already calculated return it
    if(dp[n][target] != -1) {
        return dp[n][target];
    }

    // 3. calculate result from smaller states
    int ans1 = equal_sum_partition(n-1, target);
    if(target < nums[n]) {
        dp[n][target] = ans1;
        return ans1;
    }
    int ans2 = equal_sum_partition(n-1, target - nums[n]);
    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;
}

int main() {
    int n, target = 0;
    cin>> n;

    for(int i = 1 ; i <= n ; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++){
        target += nums[i];
    }

    if (target % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= target ; j++) {
            dp[i][j] = -1;
        }
    }

    cout << equal_sum_partition(n, target / 2) << endl;

    return 0;
}
