// Given an array and a number M, find whether there exists
// a subset whose sum is equal to M.

// Time complexity: O(n*m)
// Space comlexity: O(m)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, m = 12;
    int a[] = {2, 5, 3, 4};

    bool dp[m+2] = {};
    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=1; j<=m; j++) {
            int need = j-a[i];
            if(need >= 0 && need <= m && dp[need]) dp[j] = true;
        }
    }

    for(int i = 0; i<=m; i++)
        cout << dp[i] << " ";

    return 0;
}
