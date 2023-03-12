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
        temp = output
        while(l1 or l2 or carry):
            sum = 0
            if(l1):
                sum += l1.val
                l1 = l1.next
            if(l2):
                sum += l2.val
                l2 = l2.next
            sum += carry 
            val = sum % 10
            temp.val = val
            if (sum >= 10):
                carry = 1
            else:
                carry = 0
            if(l1 or l2 or carry):
                temp.next = ListNode(0)
                temp = temp.next

        return output




s = Solution()
l1 = ListNode(2,ListNode(4,ListNode(3)))
l2 = ListNode(5,ListNode(6,ListNode(4)))
# l1.printListNode()

sum = s.addTwoNumbers(l1,l2)
sum.printListNode()