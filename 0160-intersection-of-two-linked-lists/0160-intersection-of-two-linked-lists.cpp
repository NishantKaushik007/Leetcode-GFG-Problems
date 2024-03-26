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
        int len1=1,len2=1;
        while(l1->next!=NULL)
        {
            len1++;
            l1=l1->next;
        }
        while(l2->next!=NULL)
        {
            len2++;
            l2=l2->next;
        }
        int diff=abs(len1-len2);
        l1=headA,l2=headB;
        for(int i=0;i<diff;i++)
        {
            if(len1>len2)
            {
                l1=l1->next;
            }
            if(len2>len1)
            {
                l2=l2->next;
            }
        }
        while(l1!=l2)
        {
            l1=l1->next;
            l2=l2->next;
        }
        return l1;
    }
};