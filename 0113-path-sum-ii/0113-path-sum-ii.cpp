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
vector<vector<int>> result;

    void solve(TreeNode* root, int &curr, vector<int>& temp, int targetSum){
        if(root == NULL) return;

        int nodeVal = root->val;

        curr = curr + (nodeVal);
        temp.push_back(nodeVal);

        if(root->left == NULL and root->right == NULL){

            if(curr == targetSum) result.push_back(temp);
                
        }

        else{
            solve(root->left, curr, temp, targetSum);
            solve(root->right, curr, temp, targetSum);
        }

        curr = curr - (nodeVal);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp = {};
        int curr = 0;

        solve(root, curr, temp, targetSum);

        return result;
    }
};