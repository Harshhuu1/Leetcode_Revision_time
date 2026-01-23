1class Solution:
2    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
3        n=len(mat)
4        m=len(mat[0])
5        maxi=-1e9
6        low=0
7
8        high=m-1
9        while low<=high:
10            mid=(low+high)//2
11            for i in range(n):
12                if maxi<mat[i][mid]:
13                    maxi=mat[i][mid]
14                    index=i
15            left=-1  if mid-1<=0 else mat[index][mid-1]
16            right=-1 if mid+1>=m else mat[index][mid+1]
17            
18            if mat[index][mid]>left and mat[index][mid]>right:
19                return (index,mid)
20            elif mat[index][mid]<right:
21                low=mid+1
22            else:
23                high=mid-1
24        return (-1,-1)
25
26