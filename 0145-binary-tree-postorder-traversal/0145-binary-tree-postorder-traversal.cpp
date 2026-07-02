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
    vector<int> result;
    void solve(TreeNode* node){

        if(node == NULL) return;

        solve(node->left);
        
        solve(node->right);

        result.push_back(node->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        solve(root);

        return result;

    }
};