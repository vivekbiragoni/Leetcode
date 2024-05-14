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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if (root == nullptr) {
            return traversal;
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        bool leftToRight = true;
        

        while (!nodeQueue.empty()) {
            int sz = nodeQueue.size();
            vector<int> row(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();

                int index = (leftToRight) ? i : (sz - i - 1);
                row[index] = node->val;
                if(node->left){
                    nodeQueue.push(node->left);
                }
                if(node->right){
                    nodeQueue.push(node->right);
                }
            }
            traversal.push_back(row);
            leftToRight = !leftToRight;
        }
        return traversal;
    }
};