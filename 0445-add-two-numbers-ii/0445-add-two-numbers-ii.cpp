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
    ListNode* reverse(ListNode* list)
    {
        if(list==NULL)
            return NULL;
        ListNode* curr=list,*prev=NULL;
        while(curr!=NULL)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revL1=reverse(l1);
        ListNode* revL2=reverse(l2);
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(revL1!=NULL||revL2!=NULL||carry!=0)
        {
            int sum=0;
            if(revL1!=NULL)
            {
                sum+=revL1->val;
                revL1=revL1->next;
            }
            if(revL2!=NULL)
            {
                sum+=revL2->val;
                revL2=revL2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        ListNode* ans=reverse(dummy->next);
        return ans;
    }
};