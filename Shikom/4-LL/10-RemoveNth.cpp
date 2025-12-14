# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        # Step 1: Count total nodes
        count = 0
        temp = head
        while temp:
            count += 1
            temp = temp.next

        # If removing the head itself
        if n == count:
            return head.next

        # Step 2: Move to (count - n)-th node (just before the one to delete)
        temp = head
        steps = count - n - 1   # index before the node to remove

        while steps > 0:
            temp = temp.next
            steps -= 1

        # Step 3: Delete node
        temp.next = temp.next.next

        return head
