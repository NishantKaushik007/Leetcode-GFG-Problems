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
    int getDecimalValue(ListNode* head) {
        // Step 1: Count the number of nodes
        ListNode* temp = head;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2: Compute the decimal value
        temp = head;
        int sum = 0;
        while (temp != nullptr) {
            length--; // Decrement first to get the correct exponent
            int power = 1;
            for (int i = 0; i < length; ++i) {
                power *= 2; // power = 2^length
            }
            sum += temp->val * power;
            temp = temp->next;
        }

        return sum;
    }
};