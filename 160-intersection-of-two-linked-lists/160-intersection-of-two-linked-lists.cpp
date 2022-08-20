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
        ListNode *curr1=headA,*curr2=headB;
        int c1=1,c2=1,d;
        while(curr1!=NULL)
        {
            c1++;
            curr1=curr1->next;
        }
        while(curr2!=NULL)
        {
            c2++;
            curr2=curr2->next;
        }
        d=abs(c1-c2);
        curr1=headA,curr2=headB;
        for(int i=0;i<d;i++)
        {
            if(c1>c2)
            {
                curr1=curr1->next;
                c1--;
            }
            if(c1<c2)
            {
                curr2=curr2->next;
                c2--;
            }
        }
        while(curr1!=NULL||curr2!=NULL)
        {
            if(curr1==curr2)
                return curr2;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};