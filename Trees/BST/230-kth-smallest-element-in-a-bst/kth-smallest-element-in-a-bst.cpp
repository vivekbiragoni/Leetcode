/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal will give it in the sorted order, push these node values into vector
        // and then return the value at kth index in the vector
        vector<int> traversal = inorderTraversal(root);
        return traversal[k-1];
    }
private:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> traversal;
        TreeNode* current = root;  

        while (current != nullptr || !st.empty()) {
            if (current != nullptr) {
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