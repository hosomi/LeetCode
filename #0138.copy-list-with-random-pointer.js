/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function(head) {
    const m = new Map();
    let cur = head;
    while (cur) {
        m.set(cur, new Node(cur.val));
        cur = cur.next;
    }

    cur = head;
    while (cur) {
        m.get(cur).next = cur.next ? m.get(cur.next) : null;
        m.get(cur).random = cur.random ? m.get(cur.random) : null;
        cur = cur.next;
    }
    return head ? m.get(head) : null;
};
