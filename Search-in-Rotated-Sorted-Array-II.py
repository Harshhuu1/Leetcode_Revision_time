1class Solution:
2   def search(self, nums: List[int], target: int) -> bool:
3        def serachmyway(nums: List[int], target: int):
4            index=-1
5            n=len(nums)-1
6            for i in range(n):
7                if nums[i]>nums[i+1]:
8                    index=i
9                    break
10        
11            low=0
12            high=0
13            if index==-1:
14                low,high=0,n
15            elif nums[0]<=target<=nums[index]:
16                low,high=0,index
17            else:
18                low,high=index+1,n
19            
20            while low<=high:
21                mid=(low+high)//2
22                if nums[mid]==target:
23                    return True
24                elif nums[mid]<target:
25                    low=mid+1
26                else:
27                    high=mid-1
28
29            return False
30        def real(nums: List[int], target: int):
31            low=0
32            high=len(nums)-1
33            while low<=high:
34                mid=(low+high)//2
35                if nums[mid]==target:
36                    return True
37                if nums[low]==nums[mid]==nums[high]:
38                    low+=1
39                    high-=1
40                    continue
41                
42                if nums[low]<=nums[mid]:
43                    if nums[low]<=target<nums[mid]:
44                        high=mid-1
45                    else:
46                        low=mid+1
47                else:
48                    if nums[mid]<target<=nums[high]:
49                        low=mid+1
50                    else:
51                        high=mid-1
52            return False
53        return real(nums,target)  
54
55
56