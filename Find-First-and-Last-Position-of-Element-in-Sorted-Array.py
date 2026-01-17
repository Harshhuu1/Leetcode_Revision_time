1class Solution:
2    def searchRange(self, nums: List[int], target: int) -> List[int]:
3        def upperBound(nums:List[int],x:int):
4            low=0
5            high=len(nums)-1
6            ans=len(nums)
7            
8            while low<=high:
9                mid=(low+high)//2
10                if nums[mid]>x:
11                    ans=mid
12                    high=mid-1
13                else:
14                    low=mid+1
15            return ans
16        
17        def lowerBound(nums:List[int],x:int):
18            low=0
19            high=len(nums)-1
20            ans=-1
21            lat=len(nums)
22            
23            while low<=high:
24                mid=(low+high)//2
25                if nums[mid]>=x:
26                    ans=mid
27                    high=mid-1
28                else:
29                    low=mid+1
30            return ans
31
32        init=lowerBound(nums,target)
33        if init==-1 or nums[init]!=target:
34            return [-1,-1]
35        final=upperBound(nums,target)-1
36        return [init,final]
37                
38            