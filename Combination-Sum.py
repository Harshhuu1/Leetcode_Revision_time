1class Solution:
2    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
3        output=[]
4        sum=0
5        def gen(index,ans):
6            nonlocal sum
7            # if index==len(candidates):
8            if sum==target:
9                output.append(ans[:])
10                return
11            if index==len(candidates) or sum>target:
12                return
13            ans.append(candidates[index])
14            sum+=candidates[index]
15            gen(index,ans)
16            sum-=candidates[index]
17            ans.pop()
18            gen(index+1,ans)
19        
20        gen(0,[])
21        return output
22
23            
24