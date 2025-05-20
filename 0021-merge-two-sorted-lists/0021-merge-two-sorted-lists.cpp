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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        return list2;
        if(list2==NULL)
        return list1;
        if(list1->val>list2->val)
        swap(list2,list1);
        ListNode* dummy=new ListNode(),*temp=dummy,*l1=list1,*l2=list2;
        temp->next=l1;
        while(l1&&l2)
        {
            while(l1&&l1->val<=l2->val)
            {
                l1=l1->next;
                temp=temp->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return dummy->next;
    }
};