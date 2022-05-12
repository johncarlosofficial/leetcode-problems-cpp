# [16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/)

Given an integer array `nums` of length `n` and an integer target, find three integers in `nums` such that the `sum` is closest to `target`.

Return the `sum` of the three integers.

You may assume that each input would have exactly one solution.

#### Exemple 1

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

#### Exemple 2

```
Input: nums = [0,0,0], target = 1
Output: 0
```

#### Constraints

```
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
```

### Solution

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        //first answer
        int ans = nums[0] + nums[1] + nums[2];

        //sorting the vector
        sort(nums.begin(), nums.end());

        //vector's size
        int n = nums.size();

        //loop the vector
        for(int i = 0; i < n - 2; i++){

            //pointers declaration
            int left = i + 1;
            int right = n - 1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if(sum < target){
                    left ++;
                } else{
                    right --;
                }

                //absolute values
                if(abs(target-sum) < abs(target-ans)){
                    ans = sum;
                }
            }
        }

        return ans;
    }
};
```
