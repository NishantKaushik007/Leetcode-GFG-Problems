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
            l1=l1->next;
            c1++;
        }
        while(l2!=NULL)
        {
            l2=l2->next;
            c2++;
        }
        int d=abs(c1-c2);
        l1=headA,l2=headB;
        for(int i=0;i<d;i++)
        {
            if(c1>c2)
            {
                l1=l1->next;
                c1--;
            }
            if(c2>c1)
            {
                l2=l2->next; 
                c2--;
            }
        }
        while(l1!=l2)
        {
            l1=l1->next;
            l2=l2->next;
        }
        return l2;
    }
};