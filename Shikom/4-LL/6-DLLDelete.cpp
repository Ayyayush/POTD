class Solution:
    def delPos(self, head, x):

        if head is None:
            return head

        # Case 1: delete head (x = 0)
        if x == 0:
            newHead = head.next
            if newHead is not None:
                newHead.prev = None
            return newHead

        curr = head
        index = 0

        # Move to x-th node
        while curr is not None and index < x:
            curr = curr.next
            index += 1

        # If x out of range
        if curr is None:
            return head

        # Delete curr
        if curr.prev:
            curr.prev.next = curr.next

        if curr.next:
            curr.next.prev = curr.prev

        return head
