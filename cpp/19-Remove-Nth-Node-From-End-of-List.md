# [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

#### Exemple 1

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

#### Exemple 2

```
Input: head = [1], n = 1
Output: []
```

#### Exemple 3

```
Input: head = [1,2], n = 1
Output: [1]
```

#### Constraints

```
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
```

### Solution

📌 Here, won't exactly be 'removing' anything, we'll just make it so that while traversing through the list ever again, we'll skip the node we're asked to remove. So let's do exactly that.

📌 First calculate the size of the list by taking a `listSize` variable and going through the list and incrementing `listSize` on every new node.

📌 What if we had a list of size 5 and we were asked to delete the 5th node from the back? 5th node from the back in this case would be the very first node in the list. Which means we're being asked to remove the first node in the list.

📌 So, if `listSize` and n are the same, we can just return our first node's (head's) next directly.

📌 If we were not asked to remove the first node, then let's see what we can do.

📌 Now look here, if the list is `1->2->3->4->5` and we're asked to remove `n = 2`. Our `listSize = 5`. So we have to remove (5-2) = 3rd node. But you'll ask, isn't 3rd node 3? and you're right but notice that we'll be looping from 1.

📌 So, in the first iteration, `i` will be 0 and we'll move to 2. Then `i` will be 1 and we'll move to 3. Then `i` will be 2 and we'll move to 4. Since we've looped 3 times, 0 to 3, we've arrived at 4 but that's a problem. We cannot be at 4 to remove 4. **We have to be at 3, so we can set 3's next as 5 directly instead of 4**.

📌 So, we'll loop from 0 to less than `(listSize - n) - 1`. This will make sure, we only move forward twice from 1 and arrive at 3.

📌 After we reach 3, we can directly set 3's next as 5 by using `(curr = 3 here) curr->next = curr->next->next` (`curr's next` is 4, `curr's next's next` is 5).

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int listSize = 0;
        while(curr != nullptr){
            listSize++;
            curr = curr->next;
        }

        // if n is last from the back, then that means
        // we have to remove the very first node in the list.
        // hence return head->next.
        if(listSize == n){
            return head->next;
        }

        curr = head;
        for(int i = 0; i < (listSize - n) - 1; i++){
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};
```
