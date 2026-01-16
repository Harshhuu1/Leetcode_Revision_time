1class Solution:
2    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
3        i=m-1
4        j=n-1
5        k=n+m-1
6        while i>=0  and j>=0 and k>=0:
7           
8            if nums1[i]>nums2[j]  :
9                nums1[k]=(nums1[i])
10                
11                i=i-1
12            else :
13                nums1[k]=(nums2[j])
14                
15                j=j-1
16            k-=1
17            
18       
19        while j>=0 :
20            nums1[k]=(nums2[j])
21            j=j-1
22            k=k-1
23        
24
25
26
27        