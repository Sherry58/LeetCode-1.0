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
    class BST_Iterator{
    public:
        stack<TreeNode*> st;
        bool reverse;

        BST_Iterator(TreeNode* root, bool rev){
            
            reverse = rev;

            pushAll(root);

        }

        void pushAll(TreeNode* root){
            while(root){

                st.push(root);

                if(reverse) root = root->right;

                else root = root->left;
            }
        }

        int next(){
            TreeNode* node = st.top();
            st.pop();

            if(reverse) pushAll(node->left);

            else pushAll(node->right);

            return node->val;
        }
    };
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        BST_Iterator left(root, false);
        BST_Iterator right(root, true);

        int ptr1 = left.next();
        int ptr2 = right.next();

        while(ptr1 < ptr2){
            int sum = ptr1 + ptr2;

            if(sum == k) return true;

            else if(sum < k) ptr1 = left.next();

            else ptr2 = right.next();
        }
        return false;
    }
};