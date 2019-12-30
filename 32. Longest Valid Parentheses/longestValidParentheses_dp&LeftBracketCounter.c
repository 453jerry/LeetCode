/*
 Longest Valid Parentheses
 Leetcode:32
 https://leetcode.com/problems/longest-valid-parentheses/

 Dynamic Programming
                s: ) ( ) ) ( ) ( ( ) ( ( ) ( ) ) ) 
 letfBracketCount: 0 1 0 0 1 0 1 2 1 2 3 2 3 2 1 0
               dp: 0 0 2 0 0 2 0 0 2 0 0 2 0 4 8 12
 
 Verify Parentheses:
 Traversing s, 
 if s[i] == '(' then count++
 if s[i] == ')' && count > 0 then count--; update dp[i];

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
    
    int dp[l + 1];
    memset(dp, 0, sizeof(dp));
    
    int leftBracketCount = 0;
    int result = 0;
    for (int i = 1; i <= l; i++) {
        if (s[i - 1] == '(') {
            leftBracketCount ++;
        } else if (leftBracketCount > 0) {
            leftBracketCount --;
            dp[i] = dp[i - 1] + 2;
            dp[i] += dp[i - dp[i]];

            if (dp[i] > result) {
                result = dp[i];
            }
        }
    }
    return result;
}
