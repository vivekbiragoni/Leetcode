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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize with minimum integer value
        maxSumHelper(root, maxSum);
        return maxSum;
    }
    
private:
    int maxSumHelper(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftSum = max(0, maxSumHelper(root->left, maxSum)); // Ignore negative contributions
        int rightSum = max(0, maxSumHelper(root->right, maxSum)); // Ignore negative contributions
        
        maxSum = max(maxSum, root->val + leftSum + rightSum); // Update maxSum with current path sum
        
        return root->val + max(leftSum, rightSum); // Return the max path sum including the current node
    }
};
