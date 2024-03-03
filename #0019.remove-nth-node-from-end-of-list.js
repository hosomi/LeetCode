/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let cnt = 0;
    for (node = head; node != null; node = node.next) {
        cnt++;
    }

    if (cnt - n < 1) {
        return head.next;
    }

    for (node = head, i = 1; node != null; node = node.next, i++) {
        if (i == cnt - n) {
            node.next = node.next.next;
            break;
        }
    }
    return head;
};
