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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL  || head->next==NULL)return head;
        ListNode *dummy=new ListNode(-1);
        ListNode *p,*q;
        p=head;
        q=head->next;
        head=dummy;
        while(q!=NULL)
        {
            head->next=q;
            p->next=q->next;
            q->next=p;
            head=p;
            p=p->next;
            if(p==NULL)break;
            q=p->next;
        }
        head->next=p;
        head=dummy->next;
        delete dummy;
        return head;
    }
};
