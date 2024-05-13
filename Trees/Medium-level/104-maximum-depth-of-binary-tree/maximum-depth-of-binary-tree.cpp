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
    int maxDepth(TreeNode* root) {
        int x = 0;
        int y = 0;
        if(root==0){
            return 0;
        }
        x = maxDepth(root->left);
        y = maxDepth(root->right);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }

    }
};