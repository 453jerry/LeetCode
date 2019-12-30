/*
 Longest Valid Parentheses
 Leetcode:32
 https://leetcode.com/problems/longest-valid-parentheses/

 Dynamic Programming
  s: ) ( ) ) ( ) ( ( ) ( ( ) ( ) ) ) 
 dp: 0 0 2 0 0 2 0 0 2 0 0 2 0 4 8 12
 
 Verify Parentheses:
 s[i] == ')' && s[i - 1] == '('
 If there are nested parentheses:
 s[i] == '(' && s[i - dp[i - 1] - 1] == '('

 Update the length of current parentheses substring:
 dp[i] = 2;
 If there are nested parentheses:
 dp[i] = dp[i - 1] + 2;
 Merge with previous parenthesis substring:
 dp[i] = dp[i - 1] + 2 + dp[1 - (dp[i - 1] + 2)]

 Time complexity: O(n)  
 Space complexity: O(n)

 runtime: 0ms
 */
int longestValidParentheses(char * s){
    int l = strlen(s);
    if (l == 0) {
        return 0;
    }
    
    int dp[l];
    memset(dp, 0, sizeof(dp));
    
    int result = 0;
    for (int i = 1; i < l; i++) {
        int leftBracketIndex = i - dp[i - 1] - 1;
        if (s[i] == ')' && leftBracketIndex >= 0 &&  s[leftBracketIndex] == '(') {
            dp[i] = dp[i - 1] + 2;
            if (i - dp[i] >= 0) {
                dp[i] += dp[i - dp[i]];
            }
            if (dp[i] > result) {
                result = dp[i];
            }
        }
    }
    return result;
}
