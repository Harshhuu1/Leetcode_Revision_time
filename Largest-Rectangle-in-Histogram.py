1class Solution:
2    def largestRectangleArea(self, heights: List[int]) -> int:
3        def nsl(nums):
4            st=[]
5            ans=[]
6
7            for i in range(len(nums)):
8                while st and nums[st[-1]]>=nums[i]:
9                    st.pop()
10                if not st:
11                    ans.append(-1)
12                else:
13                    ans.append(st[-1])
14                st.append(i)
15            return ans
16        def nsr(nums):
17            st=[]
18            ans=[]
19            for i in range(len(nums)-1,-1,-1):
20                while st and nums[st[-1]]>=nums[i]:
21                    st.pop()
22                if not st:
23                    ans.append(len(nums))
24                else:
25                    ans.append(st[-1])
26                st.append(i)
27            ans.reverse()
28            return ans
29        maxi=0
30        ns=nsr(heights)
31        nl=nsl(heights)
32        for i in range(len(heights)):
33            area=(ns[i]-nl[i]-1)*heights[i]
34            maxi=max(maxi,area)
35        
36        return maxi
37            
38
39        