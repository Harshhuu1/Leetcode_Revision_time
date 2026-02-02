1class Solution:
2    def subsets(self, nums: List[int]) -> List[List[int]]:
3        output=[]
4        def gen(index,ans):
5            if index==len(nums):
6                output.append(ans[:])
7                return
8            ans.append(nums[index])
9
10            gen(index+1,ans)
11            # index-=1
12            ans.pop()
13            
14            gen(index+1,ans)
15        ans=[]
16        gen(0,ans)
17        return output