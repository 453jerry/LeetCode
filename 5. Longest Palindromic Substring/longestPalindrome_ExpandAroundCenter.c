/*
 Longest Palindromic Substring
 Leetcode:5
 https://leetcode.com/problems/longest-palindromic-substring/

 Expand Around Center 
 Traverse each character in the string and use it as the center of the palindrome string.
 Expand the palindrome string as much as possible.

 Time complexity: O(n^2)  
 Space complexity: O(1)

 runtime: 4ms
 */

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int resultHead = 0;
    int resultLen  = 0;
    
    for (int i = 0; i < len; i++) {
        int head = i;
        int tail = i;
        while (tail + 1 < len && s[tail] == s[tail + 1] ) { //Skip all the same characters
            tail ++;
        }
        i = tail;
        while (head - 1 >= 0 && tail + 1 < len && s[head - 1 ] == s [tail + 1]) {
            head --;
            tail ++;
        }

        int tmpLen = tail - head + 1;
        if (tmpLen > resultLen) {
            resultHead = head;
            resultLen = tmpLen; 
        }
    }

    char *result = (char*)malloc(resultLen * sizeof(char) + 1);
    memset(result, '\0', resultLen * sizeof(char) + 1);
    strncpy(result, s + resultHead, resultLen * sizeof(char));
    return result;
}