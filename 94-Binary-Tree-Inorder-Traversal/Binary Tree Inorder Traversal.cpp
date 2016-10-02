/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> s;
        if(root==NULL)return s;
        inorder(root,s);
        return s;
    }
private:
    void inorder(TreeNode* root,vector<int> &s)
    {
        if(root->left!=NULL)inorder(root->left,s);
        s.push_back(root->val);
        if(root->right!=NULL)inorder(root->right,s);
    }
};
