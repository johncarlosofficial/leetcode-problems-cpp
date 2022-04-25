# [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/)

Given an integer `x`, return true if `x` is palindrome integer.

An integer is a **palindrome** when it reads the same backward as forward.

#### Exemple 1

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

#### Exemple 2

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

#### Exemple 3

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

#### Constraints

```
-2^31 <= x <= 2^31 - 1
```

### Solution

📌 First, we'll check if the `x < 0` or greater than 2147483647.

📌 Then, we create the `reverted` var.

📌 To revert the integer, we'll have to type:

```cpp
while(x > 0){
    reverted = reverted * 10;
    reverted = reverted + (x % 10);
    x = x/10;
}
```

📌 Lastly, we check if the reverted number is equal to the original one.

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 || x > 2147483647){
            return false;
        }
        long int reverted = 0;
        int y = x;

        //reverting the number
        while(x > 0){
            reverted = reverted * 10;
            reverted = reverted + (x % 10);
            x = x/10;
        }

        if(y == reverted){
            return true;
        } else{
            return false;
        }

    }
};
```
