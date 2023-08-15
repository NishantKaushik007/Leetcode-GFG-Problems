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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1=new ListNode(),*l2=new ListNode(),*temp1=l1,*temp2=l2,*curr=head;
        while(curr!=NULL)
        {
            if(curr->val<x)
            {
                temp1->next=new ListNode(curr->val);
                temp1=temp1->next;
            }
            else{
                temp2->next=new ListNode(curr->val);
                temp2=temp2->next;
            }
            curr=curr->next;
        }
        temp1->next=l2->next;
        return l1->next;
    }
};