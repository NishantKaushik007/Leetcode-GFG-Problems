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
        Node* curr;
        for(curr=head;curr!=NULL;)
        {
            Node* nex=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=nex;
            curr=nex;
        }
        for(curr=head;curr!=NULL;curr=curr->next->next)
            curr->next->random=(curr->random)?curr->random->next:NULL;
        Node* orignal=head,*copy=head->next,*temp=copy;
        while(orignal&&copy)
        {
            orignal->next=orignal->next->next;
            orignal=orignal->next;
            copy->next=(copy->next)?copy->next->next:NULL;
            copy=copy->next;
        }
        return temp;
    }
};