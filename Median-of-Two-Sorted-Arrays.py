1class Solution:
2    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
3        def merge( nums1: List[int], nums2: List[int]):
4            merged=[]
5            n=len(nums1)
6            m=len(nums2)
7            i=0
8            j=0
9            # k=n+m-1
10            while i<n and j<m:
11                if nums1[i]<=nums2[j]:
12                    merged.append(nums1[i])
13                    i+=1
14                else:
15                    merged.append(nums2[j])
16                    j+=1
17                    # k=-1
18            while i<n:
19                merged.append(nums1[i])
20                i+=1
21                # k-=1
22            while j<m:
23                merged.append(nums2[j])
24                j+=1
25                # k-=1
26            return merged
27
28        def noSpace(nums1: List[int], nums2: List[int]):
29            n,m=len(nums1),len(nums2)
30            total=n+m
31            total_pos=total//2
32            prev,curr=0,0
33            i=0
34            j=0
35            for k in range(total_pos+1):
36                prev=curr
37                if i<n and(j>=m or nums1[i]<=nums2[j]):
38                    curr=nums1[i]
39                    i+=1
40                else:
41                    curr=nums2[j]
42                    j+=1
43            
44            if total%2==1:
45                return float(curr)
46            else:
47                return (prev+curr)/2.0
48            
49        def Optimal( nums1: List[int], nums2: List[int]):
50            if len(nums2)<len(nums1):
51                return Optimal(nums2,nums1)
52            low=0
53            total=len(nums1)+len(nums2)
54            high=len(nums1)
55            while low<=high:
56                m1=(low+high)//2
57                m2=(len(nums1)+len(nums2)+1)//2-m1
58                l1 =-1e9 if m1==0 else nums1[m1-1]
59                l2 =-1e9 if m2==0 else nums2[m2-1]
60                r1 = 1e9 if m1 == len(nums1) else nums1[m1]
61                r2 = 1e9 if m2 == len(nums2) else nums2[m2]
62
63                if l1<=r2 and l2<=r1:
64                    if total%2==0:
65                        return (max(l1,l2)+min(r1,r2))/2
66                    else:
67                        return max(l1,l2)
68
69                elif l2>r1:
70                    low=m1+1
71
72                else:
73                    high=m1-1
74
75                    
76            return -1
77
78        return Optimal(nums1,nums2)
79
80
81
82
83
84            
85            
86