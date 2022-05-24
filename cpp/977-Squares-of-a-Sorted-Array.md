# [977. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

Given an integer array `nums` sorted in **non-decreasing order**, return an array of **the squares of each number sorted in non-decreasing order**.

#### Exemple 1

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

#### Exemple 2

```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

#### Constraints

```
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in non-decreasing order.
```

### Solution

📌 Let's take example with negative and positive numbers, like:

```
[-4, -2, 0, 1, 3]
```

📌 Since we need to put squeres in result array, we can consider that all numbers are positive (since: (-4)^2 = 4^2 = 16). Now our array looks like it sorted from middle to outside on both sides:

```
[4, 2, 0, 1, 3]
```

📌 Now, we can have two pointers `left` to left most element, `right` to most right element.

📌 Create `ans` result array same size as `nums`.

📌 Move from right to left in `res` and past `max(abs(A[l]), abs(A[r]))`, move correspondingly `l++` or `r--`.

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left = 0, right = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--){
            if (abs(nums[right]) > abs(nums[left])){
                ans[i] = nums[right] * nums[right];
                right --;
            } else {
                ans[i] = nums[left] * nums[left];
                left ++;
            }
        }

        return ans;
    }
};
```
