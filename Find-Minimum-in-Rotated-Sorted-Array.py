1class Solution:
2    def findMin(self, nums: List[int]) -> int:
3        index=-1
4        n=len(nums)-1
5        
6        # for i in range(len(nums)-1):
7        #     if nums[i]>nums[i+1]:
8        #         index=i+1
9        #         break
10        # if index==-1:
11        #     return nums[0]
12
13        # return nums[index]
14        low=0
15        high=n
16        while low<=high:
17            mid=(low+high)//2
18            if nums[mid]<nums[high]:
19                high=mid
20            elif nums[mid]>nums[high]:
21                low=mid+1
22            else:
23                high-=1
24        return nums[low]
25                
26
27
28                
29