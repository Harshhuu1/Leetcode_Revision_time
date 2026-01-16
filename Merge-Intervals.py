1class Solution:
2    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
3            intervals.sort(key=lambda x:x[0])
4            result=[]
5            result.append(intervals[0])
6            for i  in range(1,len(intervals)):
7                last=result[-1]
8                current=intervals[i]
9                if current[0]<=last[1]:
10                    last[1]=max(current[1],last[1])
11                else:
12                    result.append(current)
13            return result
14