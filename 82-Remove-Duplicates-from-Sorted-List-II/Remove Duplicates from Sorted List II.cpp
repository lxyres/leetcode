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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *s1;
        ListNode *s1_end;
        ListNode *head_next=head->next;
        s1=new ListNode(0);
        s1_end=s1;
        while(head_next!=NULL)
        {
            if(head->val==head_next->val)
            {
                int now=head_next->val;
                head=head_next->next;
                while(head!=NULL && head->val==now)head=head->next;
                if (head==NULL)break;
                else head_next=head->next;
            }
            else
            {
                s1_end->next=head;
                s1_end=head;
                head=head_next;
                head_next=head_next->next;
            }
        }
        s1_end->next=head;
        s1_end=s1->next;
        delete s1;
        return s1_end;
    }
};
