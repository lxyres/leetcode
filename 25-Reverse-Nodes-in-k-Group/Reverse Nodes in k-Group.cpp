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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL || k<2)return head;
        int tmp_number=1;
        ListNode *tmp=head->next;
        while(tmp!=NULL && tmp_number<k)
        {
            tmp_number++;
            tmp=tmp->next;
        }
        if(tmp_number<k)return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=reverseKGroup(tmp,k);
        for(int i=0;i<k;i++)
        {
            tmp=head;
            head=head->next;
            tmp->next=dummy->next;
            dummy->next=tmp;
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};
