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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k ==0 ) return head;

        // coutn nr of nodes
        ListNode * current = head;
        int len = 1;
        while(current->next){
            current = current-> next;
            len += 1;
        }

        // make it circular
        current->next = head;

        k = k % len;

        int stepsToNewHead = len - k;
        ListNode* newTail = head;
        while(--stepsToNewHead){
            newTail=newTail->next;
        }
        ListNode * newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};