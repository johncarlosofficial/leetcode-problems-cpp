# [876. Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

Given the `head` of a singly linked list, return the _middle node_ of the linked list.

If there are two middle nodes, return **the second middle** node.

#### Exemple 1

![question_876.jpg](images/question_876.jpeg)

```
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

#### Exemple 2

```
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

#### Constraints

```
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
```

### Solution

#### Fast and Slow Pointer

📌 When traversing the list with a pointer `slow`, make another pointer `fast` that traverses twice as fast. When `fast` reaches the end of the list, `slow` must be in the middle.

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```
