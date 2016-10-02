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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> s;
        if(root==NULL)return s;
        queue<TreeNode*> s2;
        s2.push(root);
        zigzagLevel(s2,s,true);
        return s;
    }
private:
    void zigzagLevel(queue<TreeNode*> &s1, vector<vector<int>> &s,bool zigzag)
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
            if(zigzag)ss.push_back(a->val);
            else ss.insert(ss.begin(),a->val);
        }
        s.push_back(ss);
        if(!s2.empty())zigzagLevel(s2,s,!zigzag);
        
    }
};
