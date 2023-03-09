# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def printListNode(self):
        while self:
            print(self.val)
            self = self.next
        

class Solution:
    def addTwoNumbers(self, l1:ListNode, l2:ListNode) -> ListNode:
        output = ListNode(0)
        carry = 0
        pow = 10
        temp = output
        while(l1):
            sum = (l1.val + l2.val) + carry
            val = (sum % 10)
            temp.val = val
            if (sum > 10):
                carry = 1
            l1 = l1.next
            l2 = l2.next
            temp.next = ListNode(0)

        return output



s = Solution()
l1 = ListNode(2,ListNode(4,ListNode(3)))
l2 = ListNode(5,ListNode(6,ListNode(4)))

sum = s.addTwoNumbers(l1,l2)
sum.printListNode()