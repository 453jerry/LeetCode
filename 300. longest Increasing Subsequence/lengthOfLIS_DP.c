/*
 Length of longest increasing subsequence
 Leetcode:300
 https://leetcode.com/problems/longest-increasing-subsequence/

 Dynamic Programming
 dp[i]=max(dp[j])+1,∀0≤j<i  
 LISlength​=max(dp[i]),∀0≤i<n

 Time complexity: O(n^2)  
 Space complexity: O(n)

 runtime: 20ms

 @param nums Input sequence
 @param numsSize Size of input squence
 @return Length of longest increasing subsequence
 */
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int maxLengthOfLIS = 1;
    int dp[numsSize]; // length of increasing subsequence between nums[0] to nums[i]

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= (dp[i] - 1); j--) {
            if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if (maxLengthOfLIS < dp[i]) {
            maxLengthOfLIS = dp[i];
        }
    }
    return maxLengthOfLIS;
}