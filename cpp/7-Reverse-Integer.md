# [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/)

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

#### Exemple 1

```
Input: x = 123
Output: 321
```

#### Exemple 2

```
Input: x = -123
Output: -321
```

#### Exemple 3

```
Input: x = 120
Output: 21
```

#### Constraints

```
-2^31 <= x <= 2^31 - 1
```

### Solution

```cpp
class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        int max = INT_MAX/10;

        while(x != 0) {

            if(abs(reversed) > max){
                return 0;
            }

            reversed *= 10;
            reversed += (x % 10);
            x /= 10;
        }

        return reversed;
    }
};
```
