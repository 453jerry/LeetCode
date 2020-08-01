/*
First Unique Character in a String
 Leetcode:387
https://leetcode.com/problems/first-unique-character-in-a-string

 Hash table

 Time complexity: O(n)  
 Space complexity: O(1)

 */

int firstUniqChar_1(char * s){
    int table[26]; //The number of repetitions of each character.
    memset(table, 0, sizeof(table));
    
    int i = 0;
    while (s[i] != '\0') {
        table[s[i] - 'a'] += 1;
        i ++;
    }
    i = 0;
    while (s[i] != '\0' ) {
        if (table[s[i] - 'a'] == 1) {
            return i;
        } else {
            i ++;
        }
    }
    return -1;
}


// Or

int firstUniqChar_2(char * s){
    int table[26]; //The position of characters first appearance.
    memset(table, -1, sizeof(table));
    
    int i = 0;
    while (s[i] != '\0') {
        int key = s[i] - 'a';
        if (table[key] >= 0) {
            table[key] = -2; // -2: the character repetition.
        } else if (table[key] == -1){
            table[key] = i; // -1: the character never appears.
        }
        i ++;
    }
    int result = -1;
    for (i = 0; i < 26; i++) {
        if (table[i] >= 0 && (result == -1 || table[i] < result)) {
            result = table[i];
        }
    }
    return result;
}
