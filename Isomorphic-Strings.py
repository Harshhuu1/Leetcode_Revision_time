1class Solution:
2    def isIsomorphic(self, s: str, t: str) -> bool:
3        mp1={}
4        mp2={}
5        if len(s)!=len(t):
6            return False
7        for i in range(len(s)):
8            if s[i] in mp1 and mp1[s[i]]!=t[i]:
9                return False
10            elif t[i] in mp2 and mp2[t[i]]!=s[i]:
11                return False
12            else:
13                mp1[s[i]]=t[i]
14                mp2[t[i]]=s[i]
15            
16        return True
17