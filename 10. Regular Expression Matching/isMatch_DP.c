/*
 Regular Expression Matching
 Leetcode:10
 https://leetcode.com/problems/regular-expression-matching/

 Dynamic Programming

 Time complexity: O(m*n)  
 Space complexity: O(m*n)

 runtime: 4ms
 */

bool isMatch(char * s, char * p){
    
    int pLen = strlen(p);
    int sLen = strlen(s);
    
    bool dp[sLen + 1][pLen + 1];
    
    //init dp
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int j = 1; j <= pLen; j++) {
        dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
    }
    
    for (int i = 1; i <= sLen; i ++) {
        for (int j = 1; j <= pLen; j++) {
            int si = i - 1;
            int pi = j - 1;
            if (p[pi] == '*') {
                dp[i][j] = dp[i][j - 2] == true || ((s[si] == p[pi - 1] || p[pi - 1] == '.') && dp[i - 1][j] == true);
            } else {
                dp[i][j] = dp[i - 1][j - 1] == true && (s[si] == p[pi] || p[pi] == '.');
            }
        }
    }
    return dp[sLen][pLen];
}

