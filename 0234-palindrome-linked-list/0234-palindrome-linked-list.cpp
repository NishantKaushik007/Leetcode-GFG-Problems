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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr=head,*prev=NULL;
        while(curr)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* dummy=new ListNode(),*slow=dummy,*fast=dummy;
        dummy->next=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revHead=reverseList(slow->next);
        slow=head;
        while(revHead)
        {
            if(revHead->val!=slow->val)
            return false;
            revHead=revHead->next;
            slow=slow->next;
        }
        return true;
    }
};