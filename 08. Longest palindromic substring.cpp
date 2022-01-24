string longestPalindrome(string s) {
    int n = s.size();
    
    // Empty string is a palindrome string
    if(n == 0) return "";
    
    bool dp[n+2][n+2];
    for(int c=0; c<=n; c++) dp[0][c] = 1, dp[1][c] = 1;
    
    int startIndex=0, endIndex=0;
    
    for(int len=2; len<=n; len++) {
        for(int index=1; index<=n-len+1; index++) {
            if(s[index-1] == s[index+len-2] && dp[len-2][index+1]) {
                dp[len][index] = 1;
                startIndex = index-1;
                endIndex = index+len-2;
            }
            else dp[len][index] = 0;
        }
    }
    
    string res = "";
    while(startIndex<=endIndex) {
        res += s[startIndex];
        startIndex++;
    }
    
    return res;
}