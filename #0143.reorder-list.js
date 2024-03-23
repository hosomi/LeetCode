/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    let nodes = [];
    let node = head;
    while (node) {
        nodes.push(node);
        node = node.next;
    }

    nodes = nodes.slice(Math.ceil(nodes.length / 2));
    node = head;
    while (nodes.length) {
      const nextNode = nodes.pop();
      let tmp = node.next;
      node.next = nextNode;
      nextNode.next = tmp;
      node = tmp;
    }

    node.next = null;
    return head;
};
