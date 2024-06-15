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
private:
    ListNode* swapPairsHelper(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* first = head;
        ListNode* second =  head->next;

        first->next = swapPairsHelper(second->next);

        second->next = first;

        return second;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return swapPairsHelper(head);
    }
};