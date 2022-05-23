# [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/)

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

#### Exemple 1

```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

#### Exemple 2

```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

#### Exemple 3

```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

#### Constraints

```
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4
```

### Solution

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int left = 0, right = nums.size();

        while(left < right){
            mid = (left + right) >> 1;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        if(nums[mid] < target){
            mid++;
        }

        return mid;
    }
};
```
