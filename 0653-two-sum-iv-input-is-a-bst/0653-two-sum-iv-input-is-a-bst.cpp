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
    unordered_set<int> st;
    bool solve(TreeNode* root, int k){
        if(root == NULL) return false;

        int remSum = k-(root->val);

        if(st.find(remSum) != st.end()){
            return true;
        }

        st.insert(root->val);

        bool path1 = solve(root->left, k);
        bool path2 = solve(root->right, k);

        if(path1 == true or path2 == true) return true;

        else return false;
    }
    bool findTarget(TreeNode* root, int k) {
        
        return solve(root, k);
    }
};