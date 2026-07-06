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
    vector<int>result;

    void solve(TreeNode* node, vector<int>& temp){

        if(node == NULL) return;

        temp.push_back(node->val);

        if(node->left == NULL and node->right == NULL){

            int num = 0;
            for(int digits : temp) num = num*10 + digits;

            result.push_back(num);
        }

        else{
            solve(node->left, temp);
            solve(node->right, temp);
        }

        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<int> temp = {};
        
        solve(root, temp);

        int sum = 0;
        for(int i : result){
            sum = sum + i; 
        }

        return sum;
    }
};