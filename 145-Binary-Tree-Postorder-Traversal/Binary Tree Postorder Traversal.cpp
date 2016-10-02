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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> s;
        if(root==NULL)return s;
        postorder(root,s);
        return s;
    }
private:
    void postorder(TreeNode* root,vector<int> &s)
    {
        if(root->left!=NULL)postorder(root->left,s);
        if(root->right!=NULL)postorder(root->right,s);
        s.push_back(root->val);
    }
};
