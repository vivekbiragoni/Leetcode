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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode* third = NULL;
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* last = NULL;

        if (first->val < second->val) {
            third = last = first;
            first = first->next;
        } else {
            third = last = second;
            second = second->next;
        }

        while (first != NULL && second != NULL) {
            if (first->val < second->val) {
                last->next = first;
                last = first;
                first = first->next;
            } else {
                last->next = second;
                last = second;
                second = second->next;
            }
        }
        if (first != NULL) {
            last->next = first;
        } else {
            last->next = second;
        }
        return third;
    }
};