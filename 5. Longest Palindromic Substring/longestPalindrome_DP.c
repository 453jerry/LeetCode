/*
 Longest Palindromic Substring
 Leetcode:5
 https://leetcode.com/problems/longest-palindromic-substring/

 Dynamic Programming

 Time complexity: O(n^2)  
 Space complexity: O(n)

 runtime: 32ms
 */
char * longestPalindrome(char * s){
    int len = strlen(s);
    if (len == 0) {
        return "";
    }
    
    int oddDPArrary[len];
    int eveDPArrary[len];
    int tmpArrary[len];
    int oddDPCount = len;
    int evenDPCount = len;
    
    //init
    for (int i = 0; i < len; i++) {
        oddDPArrary[i] = i;
        eveDPArrary[i] = i;
    }
    memset(tmpArrary, 0, sizeof(int) * len);
    
    int * oddDP = oddDPArrary;
    int * evenDP = eveDPArrary;
    int * tmp = tmpArrary;
    
    int resultHead = 0;
    int resultLen = 1;
    
    int * dp = evenDP;
    int dpCount = evenDPCount;
    int l = 2; // length of palindrom string
    while (oddDPCount != 0 || evenDPCount != 0) {
        
        int tmpIndex = 0;
        for (int i = 0; i < dpCount; i++) {
            int head = *(dp + i) - 1;
            int tail = *(dp + i) + l - 2;
            if (head >= 0 && tail < len && s[head] == s[tail]) {
                *(tmp + tmpIndex) = head;
                tmpIndex ++;
            }
        }
        
        if (tmpIndex != 0) {
            resultHead = tmp[0];
            resultLen = l;
        }
        
        if (dp == evenDP) {
            evenDP = tmp;
            evenDPCount = tmpIndex;
            tmp = dp;
            dp = oddDP;
            dpCount = oddDPCount;
        } else {
            oddDP = tmp;
            oddDPCount = tmpIndex;
            tmp = dp;
            dp = evenDP;
            dpCount = evenDPCount;
        }
        l ++;
    }
    
    char *result = (char*)malloc((resultLen + 1) * sizeof(char));
    memset(result, '\0', (resultLen + 1) * sizeof(char));
    strncpy(result, s + resultHead, resultLen * sizeof(char));
    
    return result;
}