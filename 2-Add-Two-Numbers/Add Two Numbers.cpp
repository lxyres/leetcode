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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        ListNode *head_save,*head;
        ListNode *tmp;
        tmp=new ListNode(0);
        head_save=head=tmp;
        head->val=l1->val+l2->val;
        if(head->val>=10)
        {
            (head->val)-=10;
            tmp=new ListNode(1);
        }
        else tmp=new ListNode(0);
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL && l2!=NULL)
        {
            tmp->val+=(l1->val+l2->val);
            head->next=tmp;
            head=head->next;
            if(head->val>=10)
            {
                (head->val)-=10;
                tmp=new ListNode(1);
            }
            else tmp=new ListNode(0);
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL)
        {
            while(l2!=NULL)
            {
                tmp->val+=l2->val;
                head->next=tmp;
                head=head->next;
                if(head->val>=10)
                {
                    (head->val)-=10;
                    tmp=new ListNode(1);
                }
                else tmp=new ListNode(0);
                l2=l2->next;
            }
            if (tmp->val==0)delete tmp;
            else head->next=tmp;
            return head_save;
        }
        if(l2==NULL)
        {
            while(l1!=NULL)
            {
                tmp->val+=l1->val;
                head->next=tmp;
                head=head->next;
                if(head->val>=10)
                {
                    (head->val)-=10;
                    tmp=new ListNode(1);
                }
                else tmp=new ListNode(0);
                l1=l1->next;
            }
            if (tmp->val==0)delete tmp;
            else head->next=tmp;
            return head_save;
        }
        return head_save;
    }
};
