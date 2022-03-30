# [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

#### Exemple

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

#### Exemple 2

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

#### Constraints

```
nums1.length == m

nums2.length == n

0 <= m <= 1000

0 <= n <= 1000

1 <= m + n <= 2000

-106 <= nums1[i], nums2[i] <= 106
```

### Solution

📌 First, we'll merge the two vectors using a `for` loop and the `push_back` method.

📌 Then, we sort the merged vector by using the `sort` function.

📌 When the lenght of the vector is **odd**, the median element is in the middle.

📌 When the lenght of the vector is **even**, the median element is the average to the two middle elements.

📌 Return the median.

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //merge the two vectors
        for(int i = 0;i < nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }

        //sort the merged vector
        sort(nums1.begin(),nums1.end());

        double median = 0.0;
        int len = nums1.size();
        int pointer;


        if(len%2 == 0){   //first case (even)
            pointer = len/2;
            median = (nums1[pointer-1] + nums1[pointer]) /2.0;
        } else{          //second case (odd)
            pointer = (len+1)/2;
            median = nums1[pointer-1];
        }

        return median;
    }
};
```
