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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        stack<vector<int>> st;
        vector<vector<int>> result;
        
        if(root == NULL) return{};

        q.push(root);

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
            st.push(temp);
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};