1class Solution:
2    def partition(self, s: str) -> List[List[str]]:
3        output=[]
4        def pel(s,i,j):
5            while i<=j:
6                if s[i]!=s[j]:
7                    return False
8                    break
9                i+=1
10                j-=1
11            return True
12
13        def gen(index,path):
14            if index==len(s):
15
16                output.append(path[:])
17                return
18            for i in range(index,len(s)):
19                if pel(s,index,i):
20                    path.append(s[index:i+1])
21                    gen(i+1,path)
22                    path.pop()
23            
24
25
26
27        gen(0,[])
28        return output
29        
30
31            