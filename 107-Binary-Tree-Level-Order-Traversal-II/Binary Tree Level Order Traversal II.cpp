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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> s;
        if(root==NULL)return s;
        queue<TreeNode*> s2;
        s2.push(root);
        levelOrder(s2,s);
        return s;
    }
private:
    void levelOrder(queue<TreeNode*> &s1, vector<vector<int>> &s)
    {
        vector<int> ss;
        queue<TreeNode*> s2;
        while(!s1.empty())
        {
            TreeNode* a;
            a=s1.front();
            s1.pop();
            if(a->left!=NULL)s2.push(a->left);
            if(a->right!=NULL)s2.push(a->right);
            ss.push_back(a->val);
        }
        if(!s2.empty())levelOrder(s2,s);
        s.push_back(ss);
    }
};
