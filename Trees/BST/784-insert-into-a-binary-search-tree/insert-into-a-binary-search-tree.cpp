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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode* tail = NULL;
        TreeNode* temp = root;
        while(root!=NULL){
            tail = root;
            if(val  < root->val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }

        // new node creation with given val
        TreeNode* valNode = new TreeNode(val);
        
        if(val < tail->val){
            tail->left = valNode;
        }
        else{
            tail->right = valNode;
        }
        return temp;
    }
};