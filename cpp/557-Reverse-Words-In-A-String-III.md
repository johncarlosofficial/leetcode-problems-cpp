# [557. Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

#### Exemple 1

```
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```

#### Exemple 2

```
Input: s = "God Ding"
Output: "doG gniD"
```

#### Constraints

```
1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
```

### Solution

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.size()<=1) return s;
        int i=0,j,len=s.size();
        while(i<len){
            j=i+1;
            while(s[j]!=' ' && j<len){
                j++;
            }
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
        }
        return s;
    }
};
```
