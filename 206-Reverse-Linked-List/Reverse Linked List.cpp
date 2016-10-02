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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *head_n;
        ListNode *tmp;
        head_n=new ListNode(0);
        while(head!=NULL)
        {
            tmp=head->next;
            head->next=head_n->next;
            head_n->next=head;
            head=tmp;
        }
        tmp=head_n;
        head_n=head_n->next;
        delete tmp;
        return head_n;
    }
};
