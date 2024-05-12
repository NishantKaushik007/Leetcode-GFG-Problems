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
        int c1=1,c2=1;
        while(l1!=NULL)
        {
            c1++;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            c2++;
            l2=l2->next;
        }
        int diff=abs(c1-c2);
        l1=headA,l2=headB;
        for(int i=0;i<diff;i++)
        {
            if(c1>c2)
                l1=l1->next;
            else
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