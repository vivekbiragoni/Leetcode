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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalHelper(root, result);
        return result;
    }
private:
    void preorderTraversalHelper(TreeNode* root, vector<int>& result){
        if (root != NULL){
            result.push_back(root->val);
            preorderTraversalHelper(root->left, result);
            preorderTraversalHelper(root->right, result);
        }
    }
};