# [1. Two Sum](https://leetcode.com/problems/two-sum/)

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

#### Exemple

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

#### Constraints

```
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
```

### Follow-up

Can you come up with an algorithm that is less than `O(n2)` time complexity?

### Solution

📌 As the array may not be sorted, we'll have to check each element until find the solution. So, the time complexity is O(n).

📌 We'll create an array to store the numbers. Next, in order to solve the problem, the pair for each element is: `pair = target - current`.

📌 The for loop goes through each element, and when we find a match, we add the indices to the `answer` vector using the `push_back` function.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> answer;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if((nums[i]+nums[j])==target){
                    answer.push_back(i);
                    answer.push_back(j);
                    break;
                }
            }
        }
        return answer;
    }
};

int main() {

  //vector declaration
  vector<int> nums;
  int size, e, target;

  cout << "What is the size of the vector?" << endl;
  cin >> size;

  cout << "Input the elements of the vector" << endl;

  for(int i = 0; i < size; i++){
    cin >> e;
    nums.push_back(e);
  }

  cout << "What is the target?" << endl;
  cin >> target;

  Solution obj;
  vector<int>ans = obj.twoSum(nums, target);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << endl;
  }


  return 0;

}

```
