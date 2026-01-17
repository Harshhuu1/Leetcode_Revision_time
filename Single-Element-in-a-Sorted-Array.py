1# from typing import List
2
3class Solution:
4    def singleNonDuplicate(self, nums: List[int]) -> int:
5        n = len(nums)
6        high=n-1
7        low=0
8        while low<high:
9            mid=(low+high)//2
10            if mid%2==1:
11                mid-=1
12            if nums[mid]==nums[mid+1]:
13                low=mid+2
14            else:
15                high=mid
16        return nums[low]
17        
18        