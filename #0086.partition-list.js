/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    if (head == null) {
        return head;
    }
    
		const next = new ListNode();
		const temp = new ListNode();
		next.next = temp.next = head;
		let first = next;
		let curr = temp;
		while (curr.next) {
			if (curr.next.val < x) {
				first = first.next;
				curr.next = curr.next.next;
			} else {
				first.next = first.next.next;
				curr = curr.next;
			}
		}
		first.next = temp.next;
		return next.next;
};
