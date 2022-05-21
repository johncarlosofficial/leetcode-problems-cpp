# [704. Binary Search](https://leetcode.com/problems/binary-search/)

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

#### Exemple 1

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

#### Exemple 2

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

#### Constraints

```
1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
```

### Solution

###### Intuition

**Binary search** is a textbook algorithm based on the idea to compare the target value to the middle element of the array.

If the target value is equal to the middle element - we're done.

If the target value is smaller - continue to search on the left.

If the target value is larger - continue to search on the right.

###### Algorithm

📌 Initialise left and right pointers: `left = 0`, `right = n - 1`.

📌 While `left <= right`:

📍 Compare middle element of the array `nums[pivot]` to the target value `target`.

📍 If the middle element is the target `target = nums[pivot] : return pivot`.

📍 If the target is not yet found:

📍 If `target < nums[pivot]`, continue the search on the left `right = pivot - 1`.

📍 Else continue the search on the right `left = pivot + 1`.

```cpp
class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return -1;
  }
};
```
