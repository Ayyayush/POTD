class Solution {
public:
    void deleteNode(ListNode* node) {
        // Case: If the node to be deleted is the last node, we can't delete it directly.
        // Since this is a special case where we're given the node to delete, we assume it's not the last node.
        
        // Copy the data of the next node into the current node
        node->val = node->next->val;
        
        // Delete the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp; // Deleting the next node
    }
};




//  Definition for singly-linked list.
//  class ListNode:
//      def __init__(self, x):
//          self.val = x
//          self.next = None

class Solution:
    def deleteNode(self, node):
      //  """
        :type node: ListNode
        :rtype: void
        
        // We are NOT given the head of the list.
        // So we delete the node by:
        // - Copying the value of next node into it
        // - Skipping the next node
        // """

        node.val = node.next.val          //  copy next node's value
        node.next = node.next.next        //  bypass (delete) next node
