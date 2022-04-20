# [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string s, int numRows);
```

#### Exemple 1

```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

#### Exemple 2

```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```

#### Exemple 3

```
Input: s = "A", numRows = 1
Output: "A"
```

#### Constraints

```
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
```

### Solution

```cpp
class Solution {
public:
    string convert(string s, int numRows) {

        int len = s.length();
        //if the data was to be projected in only one row
        //P A Y P A L I S H I R I N G
        if (numRows == 1)
            return s;

        //if data was to be projected in rows more than the lengh of input
        //P
        //A
        //Y
        //P
        //A
        //L
        //I
        //S
        //H
        //I
        //R
        //I
        //N
        //G

        if (numRows >= len)
            return s;

        int delta = -1; //to keep track of the direction we are supposed to move in
        //1 means down and -1 means up

        int row = 0;

        vector<char> res[numRows];

        /*
            [
                [],
                [],
                ...
                [] rows = numRows
            ]
        */

        for(auto c:s){

            /*
            res = [
                [P,    A,    G,    N], ## ROW = 0
                [A, P, L, S, I, I, G], ## ROW = 1
                [Y,    I,    R] ## ROW = 2
            ]
            */

            res[row].push_back(c);

            if(row == 0 or row == numRows - 1) // change direction
                delta *= -1;

            row += delta;
        }

        string result = "";

        for(auto x:res)
            for(auto y:x)
                result += y;

        return result;
    }
};
```
