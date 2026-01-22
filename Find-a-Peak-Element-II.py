1class Solution:
2    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
3        n=len(mat)
4        m=len(mat[0])
5
6        low=0
7        high=m-1
8        maxi=-1e9
9        index=-1
10        while low<=high:
11            mid=(low+high)//2
12            
13            for i in range(n):
14                if mat[i][mid]>maxi:
15                    maxi=mat[i][mid]
16                    index=i
17                left = mat[index][mid - 1] if mid - 1 >= 0 else -1
18                right = mat[index][mid + 1] if mid + 1 < m else -1
19            if mat[index][mid]>left and mat[index][mid]>right:
20                return (index,mid)
21            elif mat[index][mid]>right:
22                high=mid
23            else:
24                low=mid+1
25            
26        return (-1,-1)
27