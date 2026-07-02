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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if(root == NULL) return {};
        
        q.push(root);
        vector<vector<int>> result;

        while(!q.empty()){

            int levelSize = q.size();
            vector<int> temp;

            while(levelSize--){

                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if(t->left != NULL) q.push(t->left);

                if(t->right != NULL) q.push(t->right); 

            }
            result.push_back(temp);
        }
        return result;
    }
};