/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {

        int length = 0;
        ListNode temp = head;
        while (temp != null) {
            length++;
            temp = temp.next;
        }
        temp = head;

        int partLength = length / k;
        int extraNodes = length % k;
        ListNode[] arr = new ListNode[k];
        ListNode prev = null;
        for (int i = 0; i < arr.length && temp != null; i++, extraNodes--) {
            arr[i] = temp;
            for (int j = 0; j < partLength + (extraNodes > 0 ? 1 : 0)
                && temp != null; j++) {
                prev = temp;
                temp = temp.next;
            }
            prev.next = null;
        }
        return arr;
    }
}
