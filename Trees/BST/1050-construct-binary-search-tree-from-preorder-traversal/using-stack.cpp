#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr; // Base case: Empty input
        
        // Initialize the root node
        TreeNode* root = new TreeNode(preorder[0]);
        
        // Stack to keep track of parent nodes
        stack<TreeNode*> stk;
        stk.push(root); // Push the root onto the stack
        
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]); // Create new node
            
            // Check if the current node is a left child
            if (preorder[i] < stk.top()->val) {
                stk.top()->left = node; // Link the new node to the left of the current top node
                stk.push(node); // Push the new node onto the stack
            } else { // Current node is a right child
                // Find the parent node whose value is less than the current node's value
                while (!stk.empty() && stk.top()->val <= node->val) {
                    stk.pop(); // Pop the parent node off the stack
                }
                
                // Link the new node to the right of the found parent node
                stk.top()->right = node;
                stk.push(node); // Push the new node onto the stack
            }
        }
        
        return root;
    }
};
