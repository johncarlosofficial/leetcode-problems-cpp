# [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![question_17.png](images/question_17.png)

#### Exemple 1

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

#### Exemple 2

```
Input: digits = ""
Output: []
```

#### Exemple 3

```
Input: digits = "2"
Output: ["a","b","c"]
```

#### Constraints

```
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
```

### Solution

```cpp
class Solution {
public:
    void possibleCombination(string digits, vector<string> &res, string nums[], int i, string s) {

        //if the string is empty
        if(i == digits.length()) {
            res.push_back(s);
            return;
        }

        //solution
        string val = nums[digits[i] - '0'];
        for(int j = 0; j < val.size(); j++) {
            possibleCombination(digits, res, nums, i + 1, s + val[j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        //if the string is empty
        if(!digits.size()) return res;

        //vector of strings
        string nums[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        //call the function
        possibleCombination(digits, res, nums, 0, "");
        return res;
    }

};
```
