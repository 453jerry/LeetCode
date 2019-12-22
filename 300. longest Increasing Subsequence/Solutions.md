https://leetcode.com/problems/longest-increasing-subsequence/
## Dynamic Programming
 dp[i]=max(dp[j])+1,∀0≤j<i  
 LISlength​=max(dp[i]),∀0≤i<n

Time complexity: O(n^2)  
Space complexity: O(n)

### C  
Runtime: 20ms
```c
/*
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
```
## Dynamic Programming & binary search

 Dynamic Programming & binary search  

 Time complexity: O(nlogn)  
 Space complexity: O(n)

### C
Runtime: 4ms
``` c
/**
 @param nums Input sequence
 @param numsSize Size of input squence
 @return Length of longest increasing subsequence
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
```