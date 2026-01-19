1class Solution:
2    def singleNonDuplicate(self, nums: List[int]) -> int:
3        low=0
4        if len(nums)<=1:
5            return nums[0]
6        high=len(nums)-1
7        while low<high:
8            mid=(low+high)//2
9            if mid%2==1:
10                mid-=1
11            # print(mid)
12            # if mid+1<len(nums):
13            if nums[mid]==nums[mid+1]:
14                low=mid+2
15                # print(nums[high])
16            else:
17                high=mid
18            
19        # if low+1<len(nums):
20        return nums[low]
21