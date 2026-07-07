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
    vector<TreeNode*> res;

    void solve(TreeNode* root){

        if(root == NULL) return;

        solve(root->left);

        res.push_back(root);

        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        int galat = 0;
        TreeNode* p_first = NULL, *p_second = NULL, *q_first = NULL, *q_second = NULL;

        solve(root);

        for(int i = 0 ; i < res.size()-1; i++){

            if(res[i]->val >= res[i+1]->val){

                if(galat == 0){

                    galat++;
                    
                    p_first = res[i];
                    p_second = res[i+1];
                }

                else{

                    galat++;

                    q_first = res[i];
                    q_second = res[i+1];
                }
            }
        }

        if(galat == 1)  swap(p_first->val, p_second->val);

        else swap(p_first->val, q_second->val);

        return;

           
    }
};