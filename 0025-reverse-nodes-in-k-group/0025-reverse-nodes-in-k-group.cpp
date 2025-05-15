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
    ListNode* findKthNode(ListNode* temp,int k)
    {
        k-=1;
        while(k>0&&temp)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head,*prevNode=NULL;
        while(temp)
        {
            ListNode* kthNode=findKthNode(temp,k);
            if(kthNode==NULL)
            {
                if(prevNode)
                prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseList(temp);
            if(temp==head)
            head=kthNode;
            else
            prevNode->next=kthNode;
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};