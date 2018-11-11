/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *new_list_head, *new_list_last;
        if (l1->val <= l2->val) {
            new_list_head = l1;
            l1 = l1->next;
        } else {
            new_list_head = l2;
            l2 = l2->next;
        }
        new_list_last = new_list_head;
        ListNode *tmp;

        while (l2 && l1) {
            if (l1->val <= l2->val) {
                tmp = l1;
                l1 = l1->next;
            } else {
                tmp = l2;
                l2 = l2->next;
            }
            new_list_last->next = tmp;
            new_list_last = tmp;
        }

        if (l1)
            new_list_last->next = l1;
        else
            new_list_last->next = l2;

        return new_list_head;

    }
};
