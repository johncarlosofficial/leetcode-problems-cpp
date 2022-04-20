# [8. String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).

The algorithm for `myAtoi(string s)` is as follows:

1. Read in and ignore any leading whitespace.

2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.

3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.

4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).

5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.

6. Return the integer as the final result.

**Note**

- Only the space character ' ' is considered a whitespace character.

- Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

#### Exemple 1

```
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
```

#### Exemple 2

```
Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
```

#### Exemple 3

```
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
```

#### Constraints

```
0 <= s.length <= 200

s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
```

### Solution

📌 First, we'll check if the string is empty.

📌 Then, we'll remove the left blank spaces and extract the substring.

📌 We'll identify if it will be a positive or negative answer.

📌 If there's a sign, the pointer of the substring will start at index `1`.

📌 Inside a while loop, we'll `break` if we find a space or a letter.

📌 The answer is calculated by `ans = ans * 10 + s[i]-'0'`.

📌 Then, we'll check if if the answer is out of 32-bit.

```cpp
class Solution {
public:
    int myAtoi(string s) {

        //check if the string is empty
        if(s.length()==0) return 0;

        int i=0;

        //remove blank spaces
         while(i<s.size() && s[i]== ' ') {
             i++;
         }
        s = s.substr(i); //i ---> last of string

        int sign = +1;
        long ans = 0;

        // positive or negative answer
        if(s[0] == '-') sign = -1;

        int MAX = INT_MAX, MIN = INT_MIN;

        //the pointer will start at index 0 or 1
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        while(i < s.length()) {

             //check if it's a space or a letter
            if(s[0] == ' ' || !isdigit(s[i])) break;

            //formulates the answer
            ans = ans * 10 + s[i]-'0';

            //if the answer is out of 32-bit
            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && ans > MAX) return MAX;

            i++;
        }

        return (int)(sign*ans);
    }
};
```
