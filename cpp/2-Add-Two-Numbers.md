# [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#### Exemple

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

#### Exemple 2

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

#### Constraints

```
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
```

### Solution

📌 We have to Traverse Both Lists & add sum to new list.

📌 Sum is equivalent to `val1 + val2 + carry` from previous Operation.

📌 The resulting node will be `sum%10`.

📌 Carry is updated by `sum/10` for next Opeartion.

📌 Time Complexity `O(n)`.

📌 Space Compelxity `O(max(l1,l2))`.

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr = new ListNode();     //new list;
        ListNode *temp = ptr;

        int c = 0;
		//traversing both list till one of the list not reaches NULL
        while (l1 != NULL ||  l2 != NULL || c){
            int sum = 0;
		    // if l1  is not null
			// add l1-> value to sum
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1 -> next;
            }

			// if l2  is not null
			// add l2-> value to sum
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2 -> next;
            }

			// add carry to sum
            sum += c;
			// carry is updated by sum/10 because for 18 ,
			// 18 / 10 is 1 which is the carry
            c = sum/10;
			// add sum% 10 to new node as it containg the sum
            ListNode *node = new ListNode(sum%10);
            temp -> next = node;
            temp = temp -> next;
        }
        return ptr -> next;
    }
};
```
