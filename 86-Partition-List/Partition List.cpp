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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head==NULL)return head;
        ListNode *s1;
        ListNode *s1_end;
        ListNode *s2;
        ListNode *s2_end;
        s1=new ListNode(0);
        s2=new ListNode(0);
        s1_end=s1;
        s2_end=s2;
        while(head!=NULL)
        {
            if (head->val<x)
            {
                s1_end->next=head;
                s1_end=head;
                head=head->next;
            }
            else
            {
                s2_end->next=head;
                s2_end=head;
                head=head->next;
            }
        }
        s1_end->next=s2->next;
        s2_end->next=NULL;
        ListNode *tmp=s1->next;
        delete s1;
        delete s2;
        return tmp;
    }
};
