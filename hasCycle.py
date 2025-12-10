# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def hasCycle(self, head) -> bool:
        slow = head
        fast = head
        cycle = False 
        while fast is not None and fast.next is not None: 
            fast = fast.next.next
            slow = slow.next
            if slow == fast: 
                cycle = True 
                break 
        return cycle

def buildNodes(arr):
    dummy = ListNode()
    current = dummy

    for value in arr:
        current.next = ListNode(value)
        current = current.next

    return dummy.next


sol = Solution()
array = [1, 2, 3, 4, 5, 6, 7]
head = buildNodes(array)
head.next.next.next = head
print(sol.hasCycle(head))
