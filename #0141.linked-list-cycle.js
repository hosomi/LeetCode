/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let first = head;
    let second = head;
    while (second && second.next) {
        first = first.next;
        second = second.next.next;
        if (first === second) {
            return true;
        }
    }
    return false;
};
