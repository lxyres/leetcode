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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head==NULL)return head;
        unordered_map<int , ListNode*> s1;
        ListNode *tmp=head;
        int num=0;
        while(tmp!=NULL)
        {
            s1[num]=tmp;
            num++;
            tmp=tmp->next;
        }
        int now=num-n;
        if(now==0)return head->next;
        ListNode *t=s1[now-1];
        tmp=s1[now];
        t->next=tmp->next;
        delete tmp;
        return head;
    }
};
