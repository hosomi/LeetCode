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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* l1 = list1;
        for (int i = 0; i < a - 1; i++) {
            l1 = l1->next;
        }
     
        ListNode* l3 = list1;
        for (int i = 0; i < b; i++) {
            l3 = l3->next;
        }

        ListNode* l2 = list2;
        l3 = l3->next;
        l1->next=l2;
        while (l2->next != NULL) {
            l2 = l2->next;
        }
        l2->next = l3;
        return list1;
    }
};
