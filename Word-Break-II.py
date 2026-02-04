1class Solution:
2    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
3        output=[]
4        def gen(index,path):
5            if index==len(s):
6                output.append(" ".join(path))
7                return
8            
9            for i in range(index,len(s)):
10                part=s[index:i+1]
11                if part in wordDict:
12                    path.append(part)
13                    gen(i+1,path)
14                    path.pop()
15            
16        gen(0,[])
17        return output
18                