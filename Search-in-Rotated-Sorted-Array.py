1class Solution:
2    def search(self, nums: List[int], target: int) -> int:
3        ans=-1
4        index=0
5        n=len(nums)
6        for i in range (len(nums)-1):
7            if nums[i]>nums[i+1]:
8                index=i
9                break
10        
11        low=0
12        high=0
13        if index==-1:
14            low,high=0,n-1
15        elif nums[0]<=target<=nums[index]:
16            low,high=0,index
17        else:
18            low,high=index+1,n-1
19        
20        while low<=high:
21            mid=(low+high)//2
22            if nums[mid]==target:
23                return mid
24            elif nums[mid]<target:
25                low=mid+1
26            else:
27                high=mid-1
28           
29        
30        return -1
31