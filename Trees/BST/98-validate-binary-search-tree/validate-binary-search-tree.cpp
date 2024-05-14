/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> traversal = InOrder(root);
        for (size_t i = 0; i < traversal.size() - 1; ++i) {
            if (traversal[i] >= traversal[i + 1]) {
                return false; 
            }
        }
        return true;
    }

private:
    vector<int> InOrder(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> traversal;
        TreeNode* current = root;
        while (current != NULL || !st.empty()) {
            if (current != NULL) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                st.pop();
                traversal.push_back(current->val);
                current = current->right;
            }
        }
        return traversal;
    }
};