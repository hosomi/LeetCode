/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    let temp = new ListNode(0, head);
    let prev = temp;
    for(let i = 1; i < left; i++) {
        prev = prev.next;
    }

    let curr = prev.next;
    for (let i = left; i < right; i++) {
        let nextNode = curr.next;
        curr.next = nextNode.next;
        nextNode.next = prev.next;
        prev.next = nextNode;
    }
    return temp.next;
};
