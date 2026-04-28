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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* pCurrent = head;
        ListNode* pPrevious = nullptr;
        ListNode* pNext;

        while (pCurrent != nullptr)
        {
            pNext = pCurrent->next;
            pCurrent->next = pPrevious;

            pPrevious = pCurrent;
            pCurrent = pNext;
        }

        return pPrevious;
    }
};
