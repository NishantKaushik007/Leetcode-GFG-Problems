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
            return NULL;
        Node* curr=NULL;
        for(curr=head;curr!=NULL;curr=curr->next->next)
        {
            Node* temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
        }
        for(curr=head;curr!=NULL;curr=curr->next->next)
        {
            curr->next->random=(curr->random)?curr->random->next:NULL;
        }
        Node* orignal=head,*copy=head->next,*temp=copy;
        while(orignal!=NULL&&temp!=NULL)
        {
            orignal->next=orignal->next->next;
            orignal=orignal->next;
            temp->next=(temp->next)?temp->next->next:NULL;
            temp=temp->next;
        }
        return copy;
    }
};