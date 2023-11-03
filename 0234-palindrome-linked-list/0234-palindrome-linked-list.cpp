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
    ListNode* revList(ListNode* node)
    {
        if(node==NULL||node->next==NULL)
            return node;
        ListNode* revHead=revList(node->next);
        node->next->next=node;
        node->next=NULL;
        return revHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=head,*rev=revList(slow->next);
        while(rev!=NULL)
        {
            if(curr->val!=rev->val)
                return false;
            curr=curr->next;
            rev=rev->next;
        }
        return true;
    }
};