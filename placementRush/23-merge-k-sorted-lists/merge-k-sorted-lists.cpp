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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = lists.size();
        for(int i = 0; i<n; i++){
            while(lists[i]){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        if(pq.empty())return nullptr;
        ListNode * head = new ListNode(pq.top());
        pq.pop();
        ListNode * temp = head;
        while(!pq.empty()){
            ListNode * hello = new ListNode(pq.top());
            pq.pop();
            temp->next = hello;
            temp = hello;
        }
        return head;
    }
};