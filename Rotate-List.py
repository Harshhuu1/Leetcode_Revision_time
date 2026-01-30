1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution:
7    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
8        if not head:
9            return None 
10        def reverse(head):
11            curr = head
12            prev = None
13            
14            while curr:
15                nextt = curr.next
16                curr.next = prev
17                prev = curr
18                curr = nextt
19            return prev
20
21        def findKthNode(head,k):
22            curr = head
23             
24            while curr and k>1:
25                curr = curr.next
26                k -= 1
27            
28            return curr
29        
30        curr1 = head
31        count = 0 
32        while curr1:
33            curr1=curr1.next
34            count += 1
35        if count > 0:
36            k = k%count
37        if k == 0:
38            return head
39
40
41        rev_head=reverse(head)
42
43        kthNode = findKthNode(rev_head,k)
44        
45        nextNode = kthNode.next
46        kthNode.next = None
47
48        first = reverse(rev_head)
49        second = reverse(nextNode)
50        
51        curr=first
52
53        while curr.next:
54            curr=curr.next
55
56        curr.next=second
57
58        return first
59
60
61
62
63        
64
65
66
67
68        