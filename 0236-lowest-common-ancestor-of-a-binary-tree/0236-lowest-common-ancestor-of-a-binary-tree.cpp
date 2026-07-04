/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;

    int solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return 0;

        int self = 0;
        if(root == p or root == q){
            self = 1;
        }
    
        int left = solve(root->left, p, q);
        int right = solve(root->right, p, q);

        int total = left+self+right;

        if(total == 2 and ans == NULL){
            ans = root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);

        return ans;
    }
};