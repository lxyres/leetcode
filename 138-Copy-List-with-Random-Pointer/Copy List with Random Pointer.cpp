/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if (head==NULL)return head;
        unordered_map<RandomListNode*,RandomListNode*> map;
        RandomListNode* new_head;
        new_head=new RandomListNode(head->label);
        RandomListNode* s2=new_head;
        RandomListNode* s1=head->next;
        RandomListNode* tmp;
        map[head]=new_head;
        while(s1!=NULL)
        {
            tmp=new RandomListNode(s1->label);
            s2->next=tmp;
            s2=tmp;
            map[s1]=tmp;
            s1=s1->next;
        }
        map[NULL]=NULL;
        s1=head;
        s2=new_head;
        while(s1!=NULL)
        {
            s2->random=map[s1->random];
            s1=s1->next;
            s2=s2->next;
        }
        return new_head;
    }
};
