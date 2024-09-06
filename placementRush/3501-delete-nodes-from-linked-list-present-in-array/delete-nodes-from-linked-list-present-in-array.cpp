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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy->next ;
        unordered_set<int> rem(nums.begin(), nums.end());
        ListNode * prev = dummy;
        while(temp){
             if (rem.find(temp->val) != rem.end()) {  
                prev->next = temp->next;     
                delete temp;                 
                temp = prev->next; 
            }else{
                prev = temp;
                temp= temp->next;
            }
        }
        return dummy->next;
    }
};