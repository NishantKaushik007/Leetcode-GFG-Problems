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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1=headA,*l2=headB;
        int count1=1,count2=1;
        while(l1->next!=NULL)
        {
            count1++;
            l1=l1->next;
        }
        while(l2->next!=NULL)
        {
            count2++;
            l2=l2->next;
        }
        int diff=abs(count1-count2);
        l1=headA,l2=headB;
        for(int i=0;i<diff;i++)
        {
            if(count1>count2)
                l1=l1->next;
            if(count2>count1)
                l2=l2->next;
        }
        while(l1!=l2)
        {
            l1=l1->next;
            l2=l2->next;
        }
        return l1;
    }
};