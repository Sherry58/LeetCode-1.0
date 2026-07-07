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
    int galat = 0;
    TreeNode* prev = NULL;
    TreeNode* p_first = NULL, *p_second = NULL, *q_first = NULL, *q_second = NULL;

    void solve(TreeNode* root){

        if(root == NULL) return;

       solve(root->left);

       if(prev == NULL) prev = root;

       else{
            if(prev->val >= root->val){

                if(galat == 0){
                    galat++;

                    p_first = prev;
                    p_second = root;

                }

                else{
                    galat++;

                    q_first = prev;
                    q_second = root;
                }
            }

            prev = root;
        }

        solve(root->right);
    }
    void recoverTree(TreeNode* root) {

        solve(root);

        if(galat == 1)  swap(p_first->val, p_second->val);

        else swap(p_first->val, q_second->val);

        return;

           
    }
};