// Given an array and a number M, find whether there exists
// a subset whose sum is equal to M.

// Time complexity: O(n*m)
// Space comlexity: O(n*m)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, m = 12;
    int a[] = {2, 5, 3, 4};

    bool dp[n+5][m+5];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = 0;

    dp[0][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=m; j++)
        {
            int need = j-a[i-1];
            if(dp[i-1][j] == 1) dp[i][j] = 1;

            if( need>=0 && need<=m && dp[i-1][need] ) {
                dp[i][j] = 1;
            }
        }
    }
    
    for(int i=0; i<=m; i++) cout << i << " " << dp[n][i] << endl;

    return 0;
}
