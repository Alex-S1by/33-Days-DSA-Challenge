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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* result = new ListNode();
        ListNode* head = result;
        int carry = 0;

        while (t1 != NULL || t2 != NULL) {
            int sum = carry;
            if (t1) {
                sum += t1->val;
            }
            if (t2) {
                sum += t2->val;
            }
            carry = sum / 10;
            ListNode* temp = new ListNode();
            temp->val = sum % 10;
            result->next = temp;
            result = result->next;
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        if(carry) 
        {
            ListNode* temp = new ListNode();
            temp->val = carry % 10;
            result->next = temp;
        }
        return head->next;
    }
};