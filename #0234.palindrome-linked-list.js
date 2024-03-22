/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let node = head;
    let s1 = "";
    let s2 = "";
    while (node) {
        s1 = `${s1}${node.val}`;
        s2 = `${node.val}${s2}`;
        node = node.next;
    }
    return s1 === s2;
};
