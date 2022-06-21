# [392. Is Subsequence](https://leetcode.com/problems/is-subsequence/)

Given two strings `s` and `t`, return `true` if `s` is a **subsequence** of `t`, or `false` otherwise.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).

#### Exemple 1

```
Input: s = "abc", t = "ahbgdc"
Output: true
```

#### Exemple 2

```
Input: s = "axc", t = "ahbgdc"
Output: false
```

#### Constraints

```
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
```

### Solution

📌 In a loop, we'll search for each character of `t` in `s`.

📌 When we find it, we'll continue searching from that index.

📌 If all characters were found in the same order, return `true`. Otherwise, return `false`.

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int sLength = s.length();
        int tLength = t.length();

        int index = 0;

        for(int i = 0; i < tLength; i++) {
            if(s[index] ==  t[i]){
                index++;
            }
        }

        if(sLength == index) {
            return true;
        } else {
            return false;
        }
    }
};
```
