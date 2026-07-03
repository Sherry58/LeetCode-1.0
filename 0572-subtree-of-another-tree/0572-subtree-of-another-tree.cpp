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
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL and subRoot == NULL) return true;
        if(root == NULL or subRoot == NULL)  return false;
        if(root->val != subRoot->val) return false;

        bool ans1 = sameTree(root->left, subRoot->left);
        bool ans2 = sameTree(root->right, subRoot->right);

        if(ans1 == true and ans2 == true) return true;

        return false;
    }
    bool find(TreeNode* root, TreeNode* subRoot){
        if(root == NULL) return false;

        if(root->val == subRoot->val){
            if(sameTree(root, subRoot)) return true;
        }

        bool res1 = find(root->left, subRoot);
        bool res2 = find(root->right, subRoot);

        if(res1 == true or res2 == true) return true;

        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;

        if(root == NULL) return false;

        return find(root, subRoot);

    }
};