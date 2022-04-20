# [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

Given a string `s`, return the longest palindromic substring in `s`.

#### Exemple 1

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

#### Exemple 2

```
Input: s = "cbbd"
Output: "bb"
```

#### Constraints

```
1 <= s.length <= 1000
s consist of only digits and English letters.
```

### Solution

📌 First, if `s.length <= 1`, we'll return `s`.

📌 We'll create three variables: `max_len`, `n`, `start` and `end`.

📌 The palindrome's length can be odd or even, so we'll create loops for each case.

📌 Inside the for loop, we'll create a `left` pointer and a `right` pointer. If `s[left] == s[right]`, we'll decrease `left` and increase `right`.

📌 So, the palindrome's length will be `right - left - 1`. If the current length is greater than `max_len`, `max_len = len`. And the `start` pointer will be `left + 1` and the `end` pointer will be `right - 1`.

📌 Return the longest palindrome substring by using the `substr` method with the `start` point and the `max_len` point.

```cpp
class Solution {
    public:
    string longestPalindrome(string s){
        if(s.length() <= 1) return s;

        //variables declaration
        int max_len = 1;
        int n = s.length();
        int start = 0, end = 0;

        //odd length
        for(int i = 0; i < n-1; i++){
            int left = i, right = i;
            while(left >= 0 && right < n){
                if(s[left] == s[right]){
                    left--;
                    right++;
                } else {
                    break;
                }
                int len = right - left - 1;
                if(len > max_len){
                    max_len = len;
                    start = left + 1;
                    end = right - 1;
                }
            }
        }

        //even length
        for(int i = 0; i < n-1; i++){
            int left = i, right = i + 1;
            while(left >= 0 && right < n){
                if(s[left] == s[right]){
                    left--;
                    right++;
                } else {
                    break;
                }
                int len = right - left - 1;
                if(len > max_len){
                    max_len = len;
                    start = left + 1;
                    end = right - 1;
                }
            }
        }

        return s.substr(start, max_len);
    }
};
```
