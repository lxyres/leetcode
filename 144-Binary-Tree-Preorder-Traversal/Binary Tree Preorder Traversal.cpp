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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> s;
        if(root==NULL)return s;
        stack<TreeNode*> save;
        save.push(root);
        while(!save.empty())
        {
            TreeNode* a=save.top();
            save.pop();
            s.push_back(a->val);
            if(a->right!=NULL)save.push(a->right);
            if(a->left!=NULL)save.push(a->left);
            
        }
        return s;
    }
private:

};
