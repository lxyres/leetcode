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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> s;
        if(root==NULL)return s;
        queue<TreeNode*> s1;
        queue<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty())
        {
            vector<int> ss;
            while(!s1.empty())
            {
               TreeNode *a;
               a=s1.front();
               s1.pop();
               //ss.insert(ss.begin(),a->val);
               ss.push_back(a->val);
               if(a->left!=NULL)s2.push(a->left);
               if(a->right!=NULL)s2.push(a->right);
               
               
            }
            s1=s2;
            while(!s2.empty())s2.pop();
            s.push_back(ss);
        }
        return s;
    }
};
