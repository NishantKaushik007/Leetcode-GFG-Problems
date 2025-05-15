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
        for(curr=head;curr!=NULL;curr=curr->next->next)
        {
            Node* node=new Node(curr->val);
            node->next=curr->next;
            curr->next=node;
        }
        for(curr=head;curr!=NULL;curr=curr->next->next)
        curr->next->random=curr->random?curr->random->next:NULL;
        Node* original=head,*copy=head->next,*temp=copy;
        while(original)
        {
            original->next=original->next->next?original->next->next:NULL;
            original=original->next;
            copy->next=copy->next?copy->next->next:NULL;
            copy=copy->next;
        }
        return temp;
    }
};