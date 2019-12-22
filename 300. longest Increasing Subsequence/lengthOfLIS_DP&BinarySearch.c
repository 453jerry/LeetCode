/**
 Length of longest increasing subsequence
 Leetcode:300
 https://leetcode.com/problems/longest-increasing-subsequence/

 Dynamic Programming & Binary search

 Time complexity: O(nlogn)  
 Space complexity: O(n)

 runtime: 4ms

 @param nums Input sequence
 @param numsSize Size of input squence
 @return Length of longest increasing subsequence
 */
 */
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int maxLen = 0;
    int dp[numsSize]; // dp[j] is the smallest sequence tail of a increasing subsequence of all length of j+1
    memset(dp, 0xFFFFFF7F, sizeof(int) * numsSize); // init as max value of int32

    for (int i = 0; i < numsSize; i++) {
        int step = maxLen;
        int j = -1;
        while ((j + step) < maxLen && step != 0) { //Find the index of the maximum item of dp who less than nums[i] by binary search
            if (nums[i] > dp[j + step]) {
                j = j + step;
                step = (maxLen - j - 1) / 2;
            } else {
                step = step / 2;
            }
        }

        if (dp[j + 1] > nums[i]) {
            dp[j + 1] = nums[i];
            if (maxLen < j + 2) {
                maxLen = j + 2;
            }
        }
    }
    return maxLen;
}