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
    TreeNode* solve(TreeNode* node){
        if(node == NULL) return NULL;

        swap(node->left, node->right);

        solve(node->left);
        
        solve(node->right);

        return node;

    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};