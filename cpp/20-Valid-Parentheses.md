# [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

Given a string `s` containing just the characters `'(', ')', '{', '}', '[' and ']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

#### Exemple 1

```
Input: s = "()"
Output: true
```

#### Exemple 2

```
Input: s = "()[]{}"
Output: true
```

#### Exemple 3

```
Input: s = "(]"
Output: false
```

#### Constraints

```
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
```

### Solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
		//Push opening parentheses in the stack
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
				//Check that
				//1.Stack is not empty
				//2.currently read parentheses is closing of the parentheses on the top of the stack
				//If so, then pop form the stack
            else if(!st.empty() && (
                (s[i]==')' && st.top()=='(' ) ||
                (s[i]==']' && st.top()=='[') ||
                (s[i]=='}' && st.top()=='{')
            ))
                st.pop();
				//if not then return false
            else
                return false;
        }

		//Check whether stack is empty or not, for conditions where string is fully read but parentheses doesnt match, like only opening parentheses left(eg: "(((" )
        if(st.empty())
            return true;
        else
            return false;
    }
};
```
