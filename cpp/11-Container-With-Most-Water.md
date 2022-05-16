# [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Notice** that you may not slant the container.

#### Exemple 1

![question_11.jpg](images/question_11.jpg)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

#### Exemple 2

```
Input: height = [1,1]
Output: 1
```

#### Constraints

```
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
```

### Solution

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int store = 0;
        int ans = 0;
        int i=0;
        int j = n-1;
        while(i<j){
            store = min(height[i],height[j]) * (j-i);
            ans = max(ans,store);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
```
