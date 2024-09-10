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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * temp = head;
        while(temp && temp->next){
            int newval = __gcd(temp->val, temp->next->val);
            ListNode* insertnew = new ListNode(newval);
            
            insertnew->next = temp->next;
            temp->next = insertnew;
            temp = temp->next->next;
        }
        // if(temp && temp->next)
        // {cout<<__gcd(temp->val, temp->next->val);}
        return head;
    }
};