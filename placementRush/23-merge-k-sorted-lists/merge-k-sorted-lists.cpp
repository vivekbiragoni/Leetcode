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
struct compare {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> mh;

        for (ListNode* head : lists) {
            if (head) {
                mh.push(head);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!mh.empty()) {
            ListNode* mnode = mh.top();
            mh.pop();

            tail->next = mnode;
            tail = tail->next;

            if (mnode->next) {
                mh.push(mnode->next);
            }
        }
        return dummy->next;
    }
};