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
    bool solve(TreeNode* node,int &curr, int targetSum){
        if(node == NULL) return false;

        curr = curr+(node->val);

        if(node->left == NULL and node->right == NULL){
            if(curr == targetSum){
                return true;
            }
        }

        bool path1 = solve(node->left, curr, targetSum);
        bool path2 = solve(node->right, curr, targetSum);

        if(path1 == true or path2 == true) return true;

        else curr = curr - (node->val);

        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curr = 0;

        return solve(root, curr, targetSum);

    }
};