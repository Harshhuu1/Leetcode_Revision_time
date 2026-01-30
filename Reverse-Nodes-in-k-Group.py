1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution:
7    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
8        def reverse(head):
9            curr=head
10            prev=None
11            while curr:
12                nextt=curr.next
13                curr.next=prev
14                prev=curr
15                curr=nextt
16            return prev
17        
18        def findKthNode(head,k):
19            curr=head
20            while curr and k>1:
21                k-=1
22                curr=curr.next
23                
24            return curr
25        
26
27        curr = head
28        prev = None
29        while curr:
30            kthNode = findKthNode(curr,k)
31
32            if kthNode == None:
33                if prev:
34                    prev.next=curr
35                    break
36                
37            nextNode = kthNode.next
38            kthNode.next = None
39            reverse(curr)
40            if curr == head:
41                head = kthNode
42            else:
43                prev.next=kthNode
44
45            prev=curr
46            curr=nextNode
47                
48        
49        return head
50                
51            
52            
53            
54
55        
56
57        
58
59
60