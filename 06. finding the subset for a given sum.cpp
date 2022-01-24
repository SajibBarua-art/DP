// Given an array of integers and a number M,
// find whether there exists a subset whose sum is equal to M.
// print the subset.

// Time complexity: O(n*m)
// Space comlexity: O(m)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, m = 12;
    int a[] = {2, 5, 3, 4};

    int dp[m+2] = {};
    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=m; j>=a[i]; j--) {
            int need = j-a[i];
            if(dp[j] || dp[need] == 0) continue;

            dp[j] = a[i];
        }
    }

    for(int i = 0; i<=m; i++)
        cout << dp[i] << " ";

    return 0;
}