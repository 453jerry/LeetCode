/*
 Longest Common Subsequence
 Leetcode:1143
 https://leetcode.com/problems/longest-common-subsequence/

 Dynamic Programming

 Time complexity: O(n^2)  
 Space complexity: O(n)

 runtime: 4ms
 */
int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    
    if (len1 == 0 || len2 == 0) {
        return 0;
    }
    
    int result = 1;
    
    len1 += 1;
    int tmp1[len1];
    memset(tmp1, 0, sizeof(tmp1));
    int tmp2[len1];
    memset(tmp2, 0, sizeof(tmp2));
    int *dp = tmp1;
    int *oldDP = tmp2;
    
    for (int i = 0; i < len2; i++) {
        for (int j = 1; j < len1; j++) {
            if (text2[i] == text1[j - 1]) {
                dp[j] = oldDP[j - 1] + 1;
            } else {
                dp[j] = dp[j - 1] > oldDP[j] ? dp[j - 1] : oldDP[j];
            }
        }
        int *t = oldDP;
        oldDP = dp;
        dp = t;
    }
    
    return oldDP[len1 - 1];
}
