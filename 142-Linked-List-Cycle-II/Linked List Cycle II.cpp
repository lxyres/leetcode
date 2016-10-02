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
    ListNode *detectCycle(ListNode *head)
    {
        if(head==NULL )return NULL;
        ListNode *p=head;
        ListNode *q=head->next;
        while(q!=NULL)
        {
            if (p==q)
            {
                int num=1;
                p=p->next;
                while(p!=q)
                {
                    num++;
                    p=p->next;
                }
                
                if(num==1)return p;
                p=q=head;
                for(int i=0;i<num;i++)q=q->next;
                while(p!=q)
                {
                    p=p->next;
                    q=q->next;
                }
                return p;
            }
            q=q->next;
            if(q==NULL)break;
            q=q->next;
            p=p->next;
        }
        return NULL;
    }
};
