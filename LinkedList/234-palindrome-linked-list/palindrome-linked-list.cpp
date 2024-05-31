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
    bool isPalindrome(ListNode* head) {
        // using extra space
        if(!head) return true;

        stack<ListNode*> st;
        ListNode* current = head;
        while(current){
            st.push(current);
            current= current->next;
        }
        current = head;
        while(current){
            if((current->val)!=(st.top()->val)){
                return false;
            }
            current=current->next;
            st.pop();
        }
        return true;
    }
};