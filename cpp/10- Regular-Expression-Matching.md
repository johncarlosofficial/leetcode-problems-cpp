# [10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- `'.'` Matches any single character.
- `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

#### Exemple 1

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

#### Exemple 2

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

#### Exemple 3

```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

#### Constraints

```
1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
```

### Solution

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0){
            return s.size() == 0;
        }
        if (p.size() > 1 && p[1] == '*'){
            if(isMatch(s, p.substr(2))){
                return true;
            }
            if((s[0] == p[0] || p[0] == '.') && s.length() > 0){
                return isMatch(s.substr(1), p);
            }
            return false;
        }
        else {
            if((s[0] == p[0] || p[0] == '.') && s.size() > 0){
                return isMatch(s.substr(1), p.substr(1));
            }
            return false;
        }
    }
};
```
