# [1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)

Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.

Return the running sum of `nums`.

#### Exemple 1

```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

#### Exemple 2

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

#### Exemple 3

```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```

#### Constraints

```
1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
```

### Solution

📌 Declare `ans` array to store output.

📌 In a for loop, we'll calculate the sum until the `i` element.

📌 Push_back the sum of the elements to `ans`.

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans.push_back(sum);
        }

        return ans;
    }
};

```
