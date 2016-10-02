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
        if(head==NULL)return NULL;
        ListNode* s1;
        ListNode* s2;
        s1=head;
        s2=(*head).next;
        while(s2!=NULL)
        {
            if(s1->val==s2->val)
            {
                s1->next=s2->next;
                ListNode* s3;
                s3=s2;
                s2=s2->next;
                delete s3;
            }
            else
            {
                s1=s2;
                s2=s1->next;
            }
        }
        return head;
    }
};
