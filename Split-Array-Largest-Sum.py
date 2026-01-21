1class Solution:
2    def splitArray(self, nums: List[int], k: int) -> int:
3        def isValid(nums,k,mid)->bool:
4            sum=0
5            split=1
6            for i in nums:
7                sum+=i
8                if sum>mid:
9                    split+=1
10                    sum=i
11            return split<=k
12        
13        
14
15        low=max(nums)
16        high=sum(nums)
17        while low<high:
18            mid=(low+high)//2
19            if isValid(nums,k,mid):
20                high=mid
21            else:
22                low=mid+1
23            
24        return low
25