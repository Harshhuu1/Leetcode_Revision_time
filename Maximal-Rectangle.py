1class Solution:
2    def maximalRectangle(self, matrix: List[List[str]]) -> int:
3        def mah(nums):
4            def nsr(nums):
5                st=[]
6                ans=[]
7                for i in range(len(nums)-1,-1,-1):
8                    while st and nums[st[-1]]>=nums[i]:
9                        st.pop()
10                    if not st:
11                        ans.append(len(nums))
12                    else:
13                        ans.append(st[-1])
14                    st.append(i)
15                ans.reverse()
16                return ans
17            def pse(nums):
18                st=[]
19                ans=[]
20                for i in range(len(nums)):
21                    while st and nums[st[-1]]>=nums[i]:
22                        st.pop()
23                    if not st:
24                        ans.append(-1)
25                    else:
26                        ans.append(st[-1])
27                    st.append(i)
28                # ans.reverse()
29                return ans
30            ns=nsr(nums)
31            ps=pse(nums)
32            ans=0
33            for i in range(len(nums)):
34                area=(ns[i]-ps[i]-1)*nums[i]
35                ans=max(ans,area)
36            return ans
37        maxi=0
38        ans=[]
39        for j in range(len(matrix[0])):
40            ans.append(int(matrix[0][j]))
41        maxi=max(maxi,mah(ans))
42                
43
44            # maxi=max(maxi,mah(ans))
45
46        for i in range(1,len(matrix)):
47            for j in range(len(matrix[0])):
48                if matrix[i][j]=='0':
49                    ans[j]=0
50                else:
51                    ans[j]+=1
52            maxi=max(maxi,mah(ans))
53                
54            
55        return maxi
56                    
57            
58
59        
60
61