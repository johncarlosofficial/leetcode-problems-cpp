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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {

        ListNode* resultHead = new ListNode(0);
        ListNode* currentNodeInResult =resultHead;
        int carry = 0;
        while (l1 != nullptr or l2 != nullptr)
        {
            int val = 0;
            if (l1 != nullptr)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                val += l2->val;
                l2 = l2->next;
            }

            val += carry;
            carry = val / 10;
            val = val % 10;

            currentNodeInResult->next = new ListNode(val);
            currentNodeInResult = currentNodeInResult->next;
    
        }
        if (carry > 0)
        {
            currentNodeInResult->next = new ListNode(carry);
        }

        return resultHead->next;

    }
};