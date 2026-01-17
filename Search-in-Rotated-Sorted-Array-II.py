1class Solution:
2    def search(self, nums: List[int], target: int) -> bool:
3        index=-1
4        n=len(nums)-1
5        for i in range(n):
6            if nums[i]>nums[i+1]:
7                index=i
8                break
9        
10        low=0
11        high=0
12        if index==-1:
13            low,high=0,n
14        elif nums[0]<=target<=nums[index]:
15            low,high=0,index
16        else:
17            low,high=index+1,n
18        
19        while low<=high:
20            mid=(low+high)//2
21            if nums[mid]==target:
22                return True
23            elif nums[mid]<target:
24                low=mid+1
25            else:
26                high=mid-1
27
28        return False
29
30