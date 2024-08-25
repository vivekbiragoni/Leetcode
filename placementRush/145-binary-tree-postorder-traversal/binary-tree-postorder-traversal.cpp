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
private:
    void postHelper(TreeNode* node, vector<int>& ans) {
        if (node != nullptr) {
            postHelper(node->left, ans);
            postHelper(node->right, ans);
            ans.push_back(node->val);
        }
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postHelper(root, ans);
        return ans;
    }
};