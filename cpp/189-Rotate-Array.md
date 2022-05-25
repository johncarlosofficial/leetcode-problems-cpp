# [189. Rotate Array](https://leetcode.com/problems/rotate-array/)

Given an array, rotate the array to the right by `k` steps, where `k` is non-negative.

#### Exemple 1

```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

#### Exemple 2

```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

#### Constraints:

```
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 105
```

### Follow up:

Try to come up with as many solutions as you can. There are at least **three** different ways to solve this problem.
Could you do it in-place with O(1) extra space?

### Solution

```cpp
class Solution {
public:
    void reverse_range(vector<int>& nums, int i, int j) {
        while (i < j)
            swap(nums[i++], nums[j--]);
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size() <= 1) return;

        reverse_range(nums, 0, nums.size()-1);
        reverse_range(nums, k, nums.size()-1);
        reverse_range(nums, 0, k-1);
    }
};
```

###### 2nd Solution (unfinished)

```cpp
class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        int left = 0, right = nums.size();
        int start = nums.size() - k;

        for (int i = start; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }

        for (int i = 0; i < start; i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
```
