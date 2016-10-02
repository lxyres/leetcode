/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head==NULL) return NULL;
        int m=1;
        ListNode *tmp=head;
        while(tmp->next!=NULL)
        {
            m++;
            tmp=tmp->next;
        }
        tmp->next=head;
        int r=(m-k%m)%m;
        for(int i=0;i<r;i++)tmp=tmp->next;
        head=tmp->next;
        tmp->next=NULL;
        return head;
        
    }
};
