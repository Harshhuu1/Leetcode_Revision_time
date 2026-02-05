1class Solution:
2    def solveNQueens(self, n: int) -> List[List[str]]:
3        
4        def valid(row,col,board):
5            for i in range(col):
6                if board[row][i]==1:
7                    return False
8            i=row
9            j=col
10            while i>=0 and j>=0:
11                if board[i][j]==1:
12                    return False
13                j-=1
14                i-=1
15            
16            i=row
17            j=col
18            while i<n and j>=0:
19                if board[i][j]==1:
20                    return False
21                j-=1
22                i+=1
23            return True
24
25        ans=[]
26        board=[[0]*n for _ in range(n)]
27        def gen(col,board):
28            if col==n:
29                result=[]
30                for i in range(n):
31                    row=""
32                    for j in range(n):
33                        row+='Q' if board[i][j]==1 else '.'
34                    result.append(row)
35                ans.append(result)
36                return
37
38            for i in range(n):
39                if valid(i,col,board):
40                    # temp.append(col)
41                    board[i][col]=1
42                    gen(col+1,board)
43                    # temp.pop()
44                    board[i][col]=0
45            
46
47
48
49        
50            
51
52        # temp=[]
53        gen(0,board)
54        return ans
55
56
57                    
58                
59            
60            
61
62
63