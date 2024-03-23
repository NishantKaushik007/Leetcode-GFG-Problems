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
        ListNode* prev=NULL,*curr=head;
        while(curr!=NULL)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* curr,*nex;
        int len=0;
        for(curr=head;curr!=NULL;)
        {
            nex=curr->next;
            curr->next=new ListNode(curr->val);
            curr->next->next=nex;
            curr=nex;
            len++;
        }
        ListNode* orignal=head,*cpy=head->next,*temp=cpy;
        while(orignal&&temp)
        {
            orignal->next=orignal->next->next;
            orignal=orignal->next;
            temp->next=(temp->next)?temp->next->next:temp->next;
            temp=temp->next;
        }
        ListNode* revCpy=reverse(cpy);
        ListNode* prev=NULL;
        temp=revCpy;
        curr=head;
        int l=len/2;
        for(int i=0;i<l;i++)
        {
            ListNode* nex=curr->next;
            curr->next=temp;
            ListNode* tnex=temp->next;
            temp->next=nex;
            temp=tnex;
            prev=curr;
            curr=nex;
        }
        if(len%2==1)
        {
            curr->next=NULL;
        }
        else{
            prev->next->next=NULL;
        }
    }
};