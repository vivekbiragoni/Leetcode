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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans(k, nullptr);
        if (head == nullptr || head->next == nullptr) {
            ans[0]=(head);
            return ans;
        }

        int howMany = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            howMany++;
            temp = temp->next;
        }
        int initially = howMany / k;
        vector<int> lims(k, initially);
        int diff = howMany % k;
        for(int i = 0; i<diff; i++){
            lims[i]++;
        }

        temp = head;
        for (int i = 0; i < k; i++) {
            if(temp==nullptr) break;
            int cont = 1;
            ans[i] = temp;
            while (temp != nullptr && cont < lims[i]) {
                cont++;
                temp = temp->next;
            }
            if (temp!=nullptr) {
                ListNode* newhead = temp->next;
                temp->next = nullptr;
                temp = newhead;
            }
        }
        return ans;
    }
};