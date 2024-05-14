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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int balanceFactor = abs(leftHeight - rightHeight);
        
        if (balanceFactor <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        
        return false;
    }
    
private:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        return 1 + max(leftHeight, rightHeight);
    }
};
