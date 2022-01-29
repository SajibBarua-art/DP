// Problem link: https://leetcode.com/problems/unique-paths-ii/submissions/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        
        long long dp[r][c];
        memset(dp, 0, sizeof(dp));
        
        for(int i=r-1; i>=0; i--) {
            if(obstacleGrid[i][c-1] == 0) 
                dp[i][c-1] = 1;
            else break;
        }
        for(int j=c-1; j>=0; j--) {
            if(obstacleGrid[r-1][j] == 0)
                dp[r-1][j] = 1;
            else break;
        }
        
        for(int i=r-2; i>=0; i--) {
            for(int j=c-2; j>=0; j--) {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i][j+1]+dp[i+1][j];
                }
            }
        }
        
        return dp[0][0];
    }
};