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

    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) {
            return head;
        }
        
        ListNode* lnHead = head;
        while (lnHead) {
            lnHead = lnHead->next;
        }

        ListNode *lnFast = head;
        ListNode *lnFastNext = head;
        ListNode *lnFastPrev;
        
        while (lnFastNext && lnFastNext->next) {

            lnFastPrev = lnFast;
            lnFast = lnFast->next;
            lnFastNext = lnFastNext->next->next;
        }
        
        lnFastPrev->next = nullptr;
        head = sortList(head);
        lnFast = sortList(lnFast);
        
        return join(head, lnFast);
    }
    
    ListNode* join(ListNode* head, ListNode* lnFast) {

        ListNode *lnHead = new ListNode(0);
        ListNode *lnHeadTemp = lnHead;
        
        lnHeadTemp = head;
        while(lnHeadTemp){
            lnHeadTemp = lnHeadTemp->next;
        }
        
        lnHeadTemp = lnHead;
        
        while (head && lnFast) {
            if (head->val <= lnFast->val) {
                lnHeadTemp->next = head;
                head = head->next;
            } else {
                lnHeadTemp->next = lnFast;
                lnFast = lnFast->next;
            }
            lnHeadTemp = lnHeadTemp->next;
        }
        
        if (head) {
            lnHeadTemp->next = head;
        } else if (lnFast){
            lnHeadTemp->next = lnFast;
        }
        
        return lnHead->next;
    };
};
