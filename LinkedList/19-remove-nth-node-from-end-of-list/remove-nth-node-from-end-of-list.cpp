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
        ListNode *temp = head;
        int cont  = 0;
        while(temp){
            cont++;
            temp = temp->next;
        }

        int node_pos = cont - n;

        if(node_pos==0 || cont == node_pos){
            ListNode * newNode = head->next;
            delete head;
            return newNode;
        }

        temp = head;
        for(int i = 0; i < node_pos-1; ++i){
            temp = temp->next;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        return head;

    }
};