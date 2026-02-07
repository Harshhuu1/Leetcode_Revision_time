1class MinStack:
2    # st=[]
3    # ss=[]
4    def __init__(self):
5        self.st=[]
6        self.ss=[]
7
8    def push(self, val: int) -> None:
9        self.st.append(val)
10        if not self.ss or val<=self.ss[-1]:
11            self.ss.append(val)
12        return
13        
14
15    def pop(self) -> None:
16        if not self.st:
17            return
18        ans=self.st.pop()
19        if self.ss and self.ss[-1]==ans:
20            self.ss.pop()
21        return 
22
23    def top(self) -> int:
24        if not self.st:
25            return -1
26        else:
27            return self.st[-1]
28        
29
30    def getMin(self) -> int:
31        if not self.ss:
32            return -1
33        else:
34            return self.ss[-1]
35        
36
37
38# Your MinStack object will be instantiated and called as such:
39# obj = MinStack()
40# obj.push(val)
41# obj.pop()
42# param_3 = obj.top()
43# param_4 = obj.getMin()