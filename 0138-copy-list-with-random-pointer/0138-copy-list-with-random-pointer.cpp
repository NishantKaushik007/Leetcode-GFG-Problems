/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        Node* curr,*nex;
        for(curr=head;curr!=NULL;)
        {
            nex=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=nex;
            curr=nex;
        }
        for(curr=head;curr!=NULL;curr=curr->next->next)
        {
            curr->next->random=(curr->random)?curr->random->next:NULL;
        }
        Node* orignal=head,*cpy=head->next,*temp=cpy;
        while(orignal&&temp)
        {
            orignal->next=orignal->next->next;
            orignal=orignal->next;
            temp->next=(temp->next)?temp->next->next:temp->next;
            temp=temp->next;
        }
        return cpy;
    }
};