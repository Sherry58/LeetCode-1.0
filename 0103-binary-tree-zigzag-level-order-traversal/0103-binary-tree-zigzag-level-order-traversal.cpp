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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        bool zigzag = true;

        if(root == NULL) return {};

        q.push(root);
        
        while(!q.empty()){

            int levelSize = q.size();
            vector<int> temp(levelSize);
            int first = 0;
            int last = levelSize-1;

            while(levelSize--){

                TreeNode* t = q.front();
                q.pop();

                if(zigzag == true){
                    temp[first] = t->val;
                    first++;
                }
                else{
                    temp[last] = t->val;
                    last--;
                }
                if(t->left != NULL) q.push(t->left);

                if(t->right != NULL) q.push(t->right); 

            }
            zigzag = !zigzag;
            result.push_back(temp);
        }
        return result;
    }
};