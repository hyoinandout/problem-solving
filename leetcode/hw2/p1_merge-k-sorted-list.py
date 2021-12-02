#Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def merge(self,a,b):
        mergedList = ListNode()
        dummy = mergedList
        while a and b:
            if a.val < b.val:
                mergedList.next = a
                a = a.next
            else:
                mergedList.next = b
                b = b.next
            mergedList = mergedList.next
        if a:
            mergedList.next = a
        else:
            mergedList.next = b
        return dummy.next
            
    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        answer = ListNode(-10001,None)
        dummy = answer
            
        for i in range(len(lists)):
            answer = self.merge(answer,lists[i])
        return dummy.next
         