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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st,ans;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(st.empty()||st.top()->val>=curr->val)
            st.push(curr);
            else
            {
                while(!st.empty()&&st.top()->val<curr->val)
                    st.pop();
                st.push(curr);
            }
            curr=curr->next;
        }
        ListNode* dummy=new ListNode(),*temp=dummy;
        while(!st.empty())
        {
            ans.push(st.top());
            st.pop();
        }
        while(!ans.empty())
        {
            temp->next=new ListNode(ans.top()->val);
            temp=temp->next;
            ans.pop();
        }
        return dummy->next;
    }
};