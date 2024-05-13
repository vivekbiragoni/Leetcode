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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> result;

        q.push(root);

        while (!q.empty()) {

            vector<int> currentLevel;
            int levelsize = q.size();

            for (int i = 0; i < levelsize; i++) {
                TreeNode* p = q.front();
                q.pop();

                currentLevel.push_back(p->val);
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};