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
    int res = -1;

    int solve(TreeNode* root){

        if(root == NULL) return 0;

        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);

        int sum = leftHeight + rightHeight;  // gives the no of edges (+1 not used else it will give no of nodes)
        res = max(res, sum);

        int height = 1 + max(leftHeight, rightHeight); // returned to the parent as height(no of nodes from parent to leaf) the tree
        return height; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        solve(root);

        return res;

    }
};