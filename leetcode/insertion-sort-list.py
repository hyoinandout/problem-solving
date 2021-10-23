# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current = root = ListNode(0)
        while head:
            while current.next and current.next.val < head.val:
                current = current.next
            current.next,head.next,head=head,current.next,head.next
            if head and current.val > head.val:
                current = root
        return root.next
        # i = 1
        # while Optional[ListNode].next != None:
        #     pivot = head[i]
        #     j = i-1
        #     while j >= 0 and pivot <= head[j]:
        #         head[j+1] = head[j]
        #         j -= 1
        #     head[j] = pivot
                
                