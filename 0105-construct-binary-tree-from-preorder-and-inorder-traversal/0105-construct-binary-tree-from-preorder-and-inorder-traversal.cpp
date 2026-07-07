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
    int idx = 0;
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end){

        if(start > end) return NULL;

        int rootVal = preorder[idx++];
        TreeNode* root = new TreeNode (rootVal);

        int pos = mp[rootVal];

        root->left = solve(preorder, inorder, start, pos-1);
        root->right = solve(preorder, inorder, pos+1, end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start = 0, end = inorder.size() - 1;

        for(int i = 0; i < inorder.size(); i++){

            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, start, end);

    }
};