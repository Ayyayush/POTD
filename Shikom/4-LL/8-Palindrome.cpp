# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        arr = []
        temp = head
        
        # Convert linked list → array
        while temp is not None:
            arr.append(temp.val)
            temp = temp.next

        # Check palindrome using slicing
        return arr == arr[::-1]
