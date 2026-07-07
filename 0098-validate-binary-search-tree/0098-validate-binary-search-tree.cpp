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
    bool ans = true;

    void solve(TreeNode* root){

        if(root == NULL) return;

        solve(root->left);

        if(prev == NULL) prev = root;

        else{

            if(prev->val >= root->val){
                ans = false;
            }

            prev = root;

        }

        solve(root->right);
    }

    bool isValidBST(TreeNode* root) {
       
        solve(root);

        return ans;
    }
};