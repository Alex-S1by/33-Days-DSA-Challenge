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
    ListNode* doubleIt(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;

        int carry = 0;

        while (current != NULL) {
            int v = current->val;
            v = v * 2;

            if (v >= 10 && prev == nullptr) {
                head = new ListNode(1, current);
                current->val = v % 10;
            } else {

                current->val = v % 10;
                prev ? prev->val += v / 10 : NULL;
            }

            prev = current;
            current = current->next;
        }
        return head;
    }
};