/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head,*prev=NULL;
        while(curr!=NULL)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* rev=reverse(head),*curr=rev,*prev=NULL;
        int carry=0;
        while(curr!=NULL)
        {
            prev=curr;
            int value=(curr->val*2)+carry;
            curr->val=value%10;
            carry=value/10;
            curr=curr->next;
        }
        if(carry!=0)
        {
            prev->next=new ListNode(carry);
        }
        head=reverse(rev);
        return head;
    }
};