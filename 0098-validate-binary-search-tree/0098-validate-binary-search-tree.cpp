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

    TreeNode* prev = NULL;
    bool solve(TreeNode* root){
        if(root == NULL) return true;

        bool left = solve(root->left);

        if(prev != NULL && prev->val >= root->val) return false;

        prev = root; // handles all 3 cases when prev == NULL or prev->val < root->val 

        bool right = solve(root->right);

        if(left == true and right == true) return true;
        else return false;

    }
    bool isValidBST(TreeNode* root) {
       return solve(root);
    }
};