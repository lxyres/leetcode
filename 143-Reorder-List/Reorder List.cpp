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
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)return ;
        ListNode *s1;
        ListNode *s2;
        s1=head;
        int num=0;
        while(s1!=NULL)
        {
            num++;
            s1=s1->next;
        }
        int k=num-num/2-1;
        s1=head;
        for(int i=0;i<k;i++)
        {
            s1=s1->next;
        }
        s2=s1->next;
        s1->next=NULL;
        ListNode *dummy=new ListNode(0);
        k=num/2;
        while(s2!=NULL)
        {
            s1=s2;
            s2=s2->next;
            s1->next=dummy->next;
            dummy->next=s1;
        }
        s1=head;
        s2=dummy->next;
        ListNode *tmp;
        while(s2!=NULL)
        {
            tmp=s2;
            s2=s2->next;
            tmp->next=s1->next;
            s1->next=tmp;
            s1=tmp->next;
        }
        delete dummy;
    }
};
