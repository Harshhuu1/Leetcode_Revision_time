1class Solution:
2    def searchInsert(self, nums: List[int], target: int) -> int:
3        low=0
4        ans=0
5        high=len(nums)-1
6        while low<=high:
7            mid=(low+high)//2
8            if nums[mid]==target:
9                return mid
10            elif nums[mid]<target:
11                
12                low=mid+1
13            else:
14                high=mid-1
15            
16        return low