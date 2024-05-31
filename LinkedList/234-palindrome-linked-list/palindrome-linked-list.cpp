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
        // if(!head) return true;

        // stack<ListNode*> st;
        // ListNode* current = head;
        // while(current){
        //     st.push(current);
        //     current= current->next;
        // }
        // current = head;
        // while(current){
        //     if((current->val)!=(st.top()->val)){
        //         return false;
        //     }
        //     current=current->next;
        //     st.pop();
        // }
        // return true;

        // using the hare algo
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        // now my slow pointer is at the middle of the ll
        ListNode* nextNode = nullptr; 
        ListNode* prev = nullptr;
        ListNode* current = slow;
        while(current){
            nextNode = current->next;

            current->next = prev;
            prev = current;
            current= nextNode;
        }

        ListNode* start= head;
        ListNode* mid = prev;
        while(mid!=nullptr){
            if(start->val != mid->val){
                return false;
            }
            start = start->next;
            mid = mid->next;
        }
        return true;




    }
};