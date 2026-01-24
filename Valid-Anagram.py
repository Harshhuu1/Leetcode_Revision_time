1class Solution:
2    def isAnagram(self, s: str, t: str) -> bool:
3        mp1={}
4        mp2={}
5        if len(s)!=len(t):
6            return False
7        for i in range(len(s)):
8            mp1[s[i]]=mp1.get(s[i],0)+1
9            mp2[t[i]]=mp2.get(t[i],0)+1
10        if mp1==mp2:
11            return True
12        
13        return False