/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head) {
        return HasCycle(head, head?.next);
    }

    private bool HasCycle(ListNode head, ListNode fast) {
        if (head == null || fast == null || fast.next == null) {
            return false;
        }

        return head == fast ? true : HasCycle(head.next, fast.next.next);
    }
}
