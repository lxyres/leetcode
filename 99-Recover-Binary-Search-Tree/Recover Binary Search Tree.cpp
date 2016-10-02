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
    void recoverTree(TreeNode* root) 
    {
        if (root==NULL)return;
        if (root->right==root->left)return;
        TreeNode* p=root;
        TreeNode* s1=NULL;
        TreeNode* s2=NULL;
        TreeNode* last=NULL;
        while(p!=NULL)
        {
            if(p->left==NULL)
            {
                if(last==NULL || last->val<p->val)
                {
                    last=p;
                    p=p->right;
                }
                else
                {
                    if(s1==NULL)s1=last;
                    s2=p;
                    last=p;
                    p=p->right;
                }
            }
            else
            {
                TreeNode* tmp=p->left;
                while(tmp->right!=NULL && tmp->right!=p)tmp=tmp->right;
                if(tmp->right==NULL)
                {
                    tmp->right=p;
                    p=p->left;
                }
                else 
                {
                    if(last==NULL || last->val<p->val)
                    {
                        last=p;
                        tmp->right=NULL;
                        p=p->right;
                    }
                    else
                    {
                        if(s1==NULL)s1=last;
                        s2=p;
                        last=p;
                        tmp->right=NULL;
                        p=p->right;
                    }
                }
            }
        }
        swap(s1->val,s2->val);
    }
};
