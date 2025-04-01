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
        int c1=0,c2=0;
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
        int d=abs(c1-c2);
        l1=headA,l2=headB;
        while(d--)
        {
            if(c1>c2)
            l1=l1->next;
            if(c2>c1)
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