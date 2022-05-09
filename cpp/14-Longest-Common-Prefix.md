# [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

#### Exemple 1

```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

#### Exemple 2

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

#### Constraints

```
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
```

### Solution

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0, min = 1000;
        string str;

        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].length();
            if(len < min){
                min = len;
                str = strs[i];
            }
        }

        for(int i = 0; i < min; i++){
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != str[i]){
                    return str.substr(0, count);
                }
            }
            count++;
        }
        return str.substr(0, count);
    }
};t
```
