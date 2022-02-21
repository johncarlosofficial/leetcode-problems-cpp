# 1. Two Sum

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

📌 As the array may not be sorted, we'll have to check each element until find the solution. So, the time complexity is O(n).

📌 We'll create an array to store the numbers. Next, in order to solve the problem, the pair for each element is: _pair = target - current_.

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "What is the array size?" << endl;
  cin >> n;

  int array[n];
  cout << "Input each number:" << endl;
  for (int i = 0; i < n; i++){
    cin >> array[i];
  }

  int target;
  cout << "What is the target?" << endl;
  cin >> target;

  int answer[2];

  for (int i = 0; i < n; i++){
    for (int j = 1; j < n; j++){
      if (target - array[i] == array[j]){
        answer[0] = i;
        answer[1] = j;
      }
    }
  }

  cout << answer[0] << endl;
  cout << answer[1] << endl;
}

```

[leetcode website](https://leetcode.com/problems/two-sum/)
