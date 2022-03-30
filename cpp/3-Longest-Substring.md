# [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

Given a string `s`, find the length of the longest substring without repeating characters.

#### Exemple

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

#### Exemple 2

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

#### Constraints

```
0 <= s.length <= 5 * 10ˆ4

`s` consists of English letters, digits, symbols and spaces.
```

### Solution

📌 We have to Traverse Both Lists & add sum to new list.

📌 Sum is equivalent to `val1 + val2 + carry` from previous Operation.

📌 The resulting node will be `sum%10`.

📌 Carry is updated by `sum/10` for next Opeartion.

📌 Time Complexity `O(n)`.

📌 Space Complexity `O(max(l1,l2))`.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
```
