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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k ==1) return head;

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode* prevGroupEnd = dummyNode, *current = head;

        while(current){
            // check for k available nodes
            ListNode * check = current ;
            for(int i = 0; i < k ; i++){
                if(!check) return dummyNode->next;
                check = check->next;
            }

            ListNode *prev = nullptr, *next = nullptr;
            ListNode *groupStart = current;
            for(int i = 0; i < k ; i++){
                next = current->next;
                current->next = prev;
                prev = current ;
                current = next;
            }

            prevGroupEnd->next = prev;
            groupStart->next = current;

            prevGroupEnd = groupStart;
        }
        return dummyNode->next;
    }
};