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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* curr=start,*prev=start;
        while(n--)
        {
            curr=curr->next;
        }
        while(curr->next!=NULL)
        {
            curr=curr->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return start->next;
    }
};