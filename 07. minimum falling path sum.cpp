int minFallingPathSum(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    
    int dp[r][c];
    for(int j=0; j<c; j++)
        dp[0][j] = matrix[0][j];
    
    for(int i=1; i<r; i++) {
        for(int j=0; j<c; j++) {
            dp[i][j] = matrix[i][j];
            
            int mn = dp[i-1][j];
            if(j > 0) mn = min(mn, dp[i-1][j-1]);
            if(j+1 < c) mn = min(mn, dp[i-1][j+1]);
            
            dp[i][j] += mn;
        }
    }
    
    int res = INT_MAX;
    for(int j=0; j<c; j++)
        res = min(res, dp[r-1][j]);
    
    return res;
}

/*
int minFallingPathSum(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    
    int dp[r][c];
    for(int j=0; j<c; j++)
        dp[r-1][j] = matrix[r-1][j];
    
    for(int i=r-2; i>=0; i--) {
        for(int j=0; j<c; j++) {
            dp[i][j] = matrix[i][j];
            
            int mn = dp[i+1][j];
            if(j+1 < c) mn = min(mn, dp[i+1][j+1]);
            if(j-1 >= 0) mn = min(mn, dp[i+1][j-1]);
            
            dp[i][j] += mn;
        }
    }
    
    int res = INT_MAX;
    for(int j=0; j<c; j++)
        res = min(res, dp[0][j]);
    
    return res;
}
*/